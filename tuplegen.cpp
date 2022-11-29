// Sorry for the low code quality of this. I have great libraries for formatting text, parsing args, etc. but
// I wanted this to be standalone and build with any c++ compiler w/o dependencies.
// I wrote this about as fast as I could type (which is very fast), and every time I thought about a better way
// express something, ignored the thought and kept typing :-)

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <variant>

static std::string s_sCurrentIndentString;
static int s_nCurrentIndentSize = 0;
static int s_nIndentStep = 1;
static int s_nMaxArgs = 12;
static char s_cIndentChar = '\t';

static std::string s_sTupleClassName = "CTuple";
static std::string s_sCompatibleTupleClassName = "CCompatibleTuple";
static std::string s_sMemberGetName = "Get";
static std::string s_sNameSpace;

static std::string s_sConstExpr = "constexpr ";				// set to empty if no constexpr desired

std::unordered_map<std::string, std::variant<std::string *, int *, bool *> > parseTable =
{
	{ "maxargs", &s_nMaxArgs },
	{ "indent_step", &s_nIndentStep },
	{ "classname", &s_sTupleClassName },
	{ "compatclassname", &s_sCompatibleTupleClassName },
	{ "membergetname", &s_sMemberGetName },
	{ "namespace", &s_sNameSpace }
};

void Fail( char const *pMsg )
{
	printf( "fatal error %s\n arguments are:\n", pMsg );
	for( auto entries : parseTable )
	{
		printf( "  %s\n", entries.first.c_str() );
	}
	exit( 1 );
}

void CheesyArgumentParser( int argc, char **argv )
{
	
	for( int nArg = 1; nArg < argc; nArg++ )
	{
		char const *pArg = argv[nArg];
		if ( pArg[0] != '-' )
		{
			Fail( "unrecognized arg" );
		}
		while( pArg[0] == '-' )
		{
			pArg++;											// let them type -arg or --arg if they want
		}
		auto findIt = parseTable.find( pArg );
		if ( findIt == parseTable.end() )
		{
			Fail( "unrec arg" );
		}
		std::variant<std::string *, int *, bool *> varPtr = findIt->second;
		switch( varPtr.index() )
		{
			case 0:											// string arg
			{
				if ( nArg == argc -1 )
				{
					Fail( "arg missing argument" );
				}
				*( std::get<0>( varPtr ) ) = argv[++nArg];
			}
			break;

			case 1:											// int
			{
				if ( nArg == argc -1 )
				{
					Fail( "arg missing int argument" );
				}
				*( std::get<1>( varPtr ))  = atoi( argv[++nArg] ); // no error check, don't care.
			}
			break;

			case 2:											// bool, set var to true if found
			{
				*( std::get<2>( varPtr ) ) = true;
			}
			break;
		}
	}
}


void AdjustIndent( int nNumStopsDelta )
{
	s_nCurrentIndentSize += nNumStopsDelta;
	s_sCurrentIndentString.clear();
	for( int i = 0; i < s_nIndentStep * s_nCurrentIndentSize; i++ )
	{
		s_sCurrentIndentString.push_back( s_cIndentChar );
	}
	
}

void Print( char const *pString )
{
	printf( "%s", pString );
}

void Print( std::string const &str )
{
	Print(  str.c_str() );
}

void Print( int x )
{
	printf( "%d", x );
}

void Print( char c )
{
	printf( "%c", c );
}

template<typename... ArgTypes>
void Print( const ArgTypes&... values )
{
	( Print( values ), ...);
}

template<typename... ArgTypes>
void PrintLn( const ArgTypes&... values )
{
	Print( s_sCurrentIndentString );
	( Print( values ), ...);
	printf( "\n" );
}

void PrintTupleDef( int nNumFields, std::string const &className, bool bUseCompatibleLayout  )
{
	PrintLn( "template<typename ...types> class ", className, ";\n" );
	std::string sTemplateArgs = "<";
	std::string sTypeList = "";
	for( int nArg = 0; nArg < nNumFields; nArg++ )
	{
		sTemplateArgs += "typename Type";
		if ( nArg > 9 )
		{
			sTemplateArgs.push_back( '0' + ( nArg / 10 ) );
		}
		sTemplateArgs.push_back( '0' + ( nArg % 10 ) );
		sTemplateArgs += "_t";
		sTypeList += "Type";
		if ( nArg > 9 )
		{
			sTypeList.push_back( '0' + ( nArg / 10 ) );
		}
		sTypeList.push_back( '0' + ( nArg % 10 ) );
		sTypeList += "_t";

		if ( nArg != nNumFields -1 )
		{
			sTemplateArgs += ", ";
			sTypeList += ",";
		}
	}
	sTemplateArgs += ">";
	
	if ( s_sNameSpace.size() )
	{
		PrintLn( "namespace ", s_sNameSpace );
		PrintLn( "{" );
		AdjustIndent( 1 );
	}

	PrintLn( "template ", sTemplateArgs );
	PrintLn( "class ", className, "<", sTypeList, ">" );
	PrintLn( "{" );
	PrintLn( "public:" );
	AdjustIndent( 1 );
	if ( bUseCompatibleLayout )								// put the fields in reverse order?
	{
		for( int i = nNumFields -1; i >= 0; i-- )
		{
			PrintLn( "Type", i, "_t _", i, ';' );
		}
	}
	else
	{
		for( int i = 0; i < nNumFields; i++ )
		{
			PrintLn( "Type", i, "_t _", i, ';' );
		}
	}

	if ( bUseCompatibleLayout )
	{
		// if fields are stored in reverse order, generate constructors so you can give them in the right order like STL tuple
		for( char const *passingConvention : { "const &", "&&" } )		// move and non-move constr
		{
			Print( s_sCurrentIndentString, s_sConstExpr, " FORCEINLINE ", className, "( " );
			for( int i = 0; i < nNumFields; i++ )
			{
				Print( "Type", i, "_t ", passingConvention, "val", i );
				if ( i != nNumFields - 1 )
				{
					Print( ", " );
				}
			}
			Print( " )\n" );
			PrintLn( "{" );
			AdjustIndent( 1 );
			for( int i = 0; i < nNumFields; i++ )
			{
				PrintLn( "_", i, " = val", i, ";" );
			}
			AdjustIndent( -1 );
			PrintLn( "}" );
		}
	}
	
	PrintLn();
	PrintLn( "FORCEINLINE ", s_sConstExpr, "auto & operator=( std::tuple<", sTypeList, "> const &tuple )" );
	PrintLn( "// Assignment from STL tuple" );
	PrintLn( "{" );
	AdjustIndent( 1 );
	for( int i = 0; i < nNumFields; i++ )
	{
		PrintLn( "_", i, " = std::get<", i, ">( tuple );" );
	}
	PrintLn( "return *this;" );
	AdjustIndent( -1 );
	PrintLn( "}" );

	// now, output member get<int> functions. if constexpr required, 
	for( char const *pConst : { " ", " const " } )
	{
		PrintLn( "template<int nFieldID>" );
		PrintLn( "FORCEINLINE ", s_sConstExpr, "auto", pConst, "& ", s_sMemberGetName, "()", pConst );
		PrintLn( "// Member get function by field index" );
		PrintLn( "{" );
		AdjustIndent( 1 );
		PrintLn( "static_assert( ( nFieldID >= 0 ) && ( nFieldID < ", nNumFields, " ) );" );
		for( int i = 0; i < nNumFields; i++ )
		{
			PrintLn( "if constexpr( nFieldID == ", i, ")" );
			PrintLn( "{" );
			AdjustIndent( 1 );
			PrintLn( "return _", i, ";" );
			AdjustIndent( -1 );
			PrintLn( "}" );
		}
		AdjustIndent( -1 );
		PrintLn( "}\n" );
	}

	// now, output member get<type> functions. c++17 required for if constexpr. if not c++17, you can remove them
	for( char const *pConst : { " ", " const " } )
	{
		PrintLn( "template<typename fieldType>" );
		PrintLn( "FORCEINLINE ", s_sConstExpr, "auto", pConst, "& ", s_sMemberGetName, "()", pConst );
		PrintLn( "// Member get function by field type" );
		PrintLn( "{" );
		AdjustIndent( 1 );
		for( int i = 0; i < nNumFields; i++ )
		{
			PrintLn( "if constexpr( std::is_same_v<fieldType, Type", i, "_t> )" );
			PrintLn( "{" );
			AdjustIndent( 1 );
			for( int j = i + 1 ; j < nNumFields; j++ )		// check for duplicate types
			{
				PrintLn( "static_assert( ! std::is_same_v<fieldType, Type", j, "_t>, \"Duplicate types in Get<type>\" );" );
			}
			PrintLn( "return _", i, ";" );
			AdjustIndent( -1 );
			PrintLn( "}" );
		}
		AdjustIndent( -1 );
		PrintLn( "}\n" );
	}
	
	
	PrintLn( "FORCEINLINE ", s_sConstExpr, "operator std::tuple<", sTypeList, ">() const"  );
	PrintLn( "// Convert to STL tuple" );
	PrintLn( "{" );
	AdjustIndent( 1 );
	Print( s_sCurrentIndentString, "return { " );
	for( int i = 0; i < nNumFields; i++ )
	{
		int nIndex = ( bUseCompatibleLayout ) ? ( nNumFields -1 ) - i : i;
		Print( "_", nIndex );
		if ( i != nNumFields - 1 )
		{
			Print( ", " );
		}
	}
	Print( " };\n" );
	AdjustIndent( -1 );
	PrintLn( "}\n" );

	if ( bUseCompatibleLayout )								// can't convert to a reference if fileds aren't in the same order
	{
		PrintLn( "FORCEINLINE operator std::tuple<", sTypeList, "> &()" );
		PrintLn( "// Convert to writable reference to std::tuple. **Warning**, bad idea to do this on a temporary value" );
		PrintLn( "{" );
		AdjustIndent( 1 );
		PrintLn( "return *(( std::tuple<", sTypeList, "> * ) this );" );
		AdjustIndent( -1 );
		PrintLn( "}\n" );
	}
	
	PrintLn( "FORCEINLINE auto operator<=>( ", className, "<", sTypeList, "> const &other ) const = default;" );
	PrintLn( "// spaceship comparison operator\n" );
	
	PrintLn( "FORCEINLINE void swap( ", className, "<", sTypeList, "> &other )" );
	PrintLn( "// member swap" );
	PrintLn( "{" );
	AdjustIndent( 1 );
	PrintLn( "std::swap( *this, other );" );
	AdjustIndent( -1 );
	PrintLn( "}" );
	AdjustIndent( -1 );
	PrintLn( "};\n" );

	
	PrintLn( "// Deduction guide:" );
	PrintLn( "template", sTemplateArgs );
	Print( s_sCurrentIndentString, className, "( " );
	for( int i = 0; i < nNumFields; i++ )
	{
		Print( "Type", i, "_t arg", i );
		if ( i != nNumFields -1 )
		{
			Print( ", " );
		}
	}
	Print( " ) -> ", className, "<", sTypeList, ">;\n" );
	if ( s_sNameSpace.size() )
	{
		AdjustIndent( -1 );
		PrintLn( "};" );
	}
}

void GenTuple( std::string const &className, bool bCompat )
{
	for( int i = 1; i <= s_nMaxArgs; i++ )
	{
		PrintTupleDef( i, className, bCompat );
	}

	// PrintLn( "// Deduction guide for constructing from a tuple" );
	// PrintLn( "template<typename ...types>" );
	// PrintLn( " ", className, "( std::tuple<types...> const & ) -> ", className, "<types...>;" );

	PrintLn( "// Override of std::get" );
	PrintLn( "namespace std\n{" );
	AdjustIndent( 1 );
	PrintLn( "template<int nFieldID, typename ...types> FORCEINLINE ", s_sConstExpr, "auto const & get( ", className, "<types...> const &tuple ) { return tuple.template Get<nFieldID>(); }" );
	PrintLn( "template<int nFieldID, typename ...types> FORCEINLINE ", s_sConstExpr, "auto & get( ", className, "<types...> &tuple ) { return tuple.template Get<nFieldID>(); }" );
	PrintLn( "template<typename fieldType, typename ...types> FORCEINLINE ", s_sConstExpr, "auto get( ", className, "<types...> const &tuple ) { return tuple.template Get<fieldType>(); }" );
	PrintLn( "template<typename fieldType, typename ...types> FORCEINLINE ", s_sConstExpr, "auto get( ", className, "<types...> &tuple ) { return tuple.template Get<fieldType>(); }" );
	PrintLn( "// Deduction guide for constructing a tuple" );
	PrintLn( "template<typename ...types>" );
	PrintLn( " std::tuple( ", className, "<types...> const & ) -> std::tuple<types...>;" );


	AdjustIndent( -1 );
	PrintLn( "}\n" );
}

int main( int argc, char **argv )
{
	CheesyArgumentParser( argc, argv );

	PrintLn( "#pragma once\n#include <tuple>" );
	PrintLn( "#include <type_traits>\n" );
	PrintLn( "#ifndef FORCEINLINE" );
	AdjustIndent( 1 );
	PrintLn( "#ifdef __GNUC__" );
	AdjustIndent( 1 );
	PrintLn( "#define FORCEINLINE inline __attribute__((always_inline))" );
	AdjustIndent( - 1 );
	PrintLn( "#elif defined(  _MSC_VER )" );
	AdjustIndent( 1 );
	PrintLn( "#define FORCEINLINE __forceinline" );
	AdjustIndent( -1 );
	PrintLn( "#endif" );
	AdjustIndent( -1 );
	PrintLn( "#endif" );
	GenTuple( s_sTupleClassName, false );
	GenTuple( s_sCompatibleTupleClassName, true );
}
