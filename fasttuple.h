#pragma once
#include <tuple>
#include <type_traits>

#ifndef FORCEINLINE
	#ifdef __GNUC__
		#define FORCEINLINE inline __attribute__((always_inline))
	#elif defined(  _MSC_VER )
		#define FORCEINLINE __forceinline
	#endif
#endif
template<typename ...types> class CTuple;

template <typename Type0_t>
class CTuple<Type0_t>
{
public:
	Type0_t _0;
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 1 ) );
		if constexpr( nFieldID == 0)
		{
			return _0;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 1 ) );
		if constexpr( nFieldID == 0)
		{
			return _0;
		}
	}

	template<typename fieldType>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field type
	{
		if constexpr( std::is_same_v<fieldType, Type0_t> )
		{
			return _0;
		}
	}

	template<typename fieldType>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field type
	{
		if constexpr( std::is_same_v<fieldType, Type0_t> )
		{
			return _0;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t>() const
	// Convert to STL tuple
	{
		return { _0 };
	}

	FORCEINLINE auto operator<=>( CTuple<Type0_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CTuple<Type0_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t>
CTuple( Type0_t arg0 ) -> CTuple<Type0_t>;
template<typename ...types> class CTuple;

template <typename Type0_t, typename Type1_t>
class CTuple<Type0_t,Type1_t>
{
public:
	Type0_t _0;
	Type1_t _1;
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 2 ) );
		if constexpr( nFieldID == 0)
		{
			return _0;
		}
		if constexpr( nFieldID == 1)
		{
			return _1;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 2 ) );
		if constexpr( nFieldID == 0)
		{
			return _0;
		}
		if constexpr( nFieldID == 1)
		{
			return _1;
		}
	}

	template<typename fieldType>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field type
	{
		if constexpr( std::is_same_v<fieldType, Type0_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type1_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			return _1;
		}
	}

	template<typename fieldType>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field type
	{
		if constexpr( std::is_same_v<fieldType, Type0_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type1_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			return _1;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t>() const
	// Convert to STL tuple
	{
		return { _0, _1 };
	}

	FORCEINLINE auto operator<=>( CTuple<Type0_t,Type1_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CTuple<Type0_t,Type1_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t>
CTuple( Type0_t arg0, Type1_t arg1 ) -> CTuple<Type0_t,Type1_t>;
template<typename ...types> class CTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t>
class CTuple<Type0_t,Type1_t,Type2_t>
{
public:
	Type0_t _0;
	Type1_t _1;
	Type2_t _2;
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 3 ) );
		if constexpr( nFieldID == 0)
		{
			return _0;
		}
		if constexpr( nFieldID == 1)
		{
			return _1;
		}
		if constexpr( nFieldID == 2)
		{
			return _2;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 3 ) );
		if constexpr( nFieldID == 0)
		{
			return _0;
		}
		if constexpr( nFieldID == 1)
		{
			return _1;
		}
		if constexpr( nFieldID == 2)
		{
			return _2;
		}
	}

	template<typename fieldType>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field type
	{
		if constexpr( std::is_same_v<fieldType, Type0_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type1_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			return _2;
		}
	}

	template<typename fieldType>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field type
	{
		if constexpr( std::is_same_v<fieldType, Type0_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type1_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			return _2;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t>() const
	// Convert to STL tuple
	{
		return { _0, _1, _2 };
	}

	FORCEINLINE auto operator<=>( CTuple<Type0_t,Type1_t,Type2_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CTuple<Type0_t,Type1_t,Type2_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t>
CTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2 ) -> CTuple<Type0_t,Type1_t,Type2_t>;
// Override of std::get
namespace std
{
	template<int nFieldID, typename ...types> FORCEINLINE constexpr auto const & get( CTuple<types...> const &tuple ) { return tuple.template Get<nFieldID>(); }
	template<int nFieldID, typename ...types> FORCEINLINE constexpr auto & get( CTuple<types...> &tuple ) { return tuple.template Get<nFieldID>(); }
	template<typename fieldType, typename ...types> FORCEINLINE constexpr auto get( CTuple<types...> const &tuple ) { return tuple.template Get<fieldType>(); }
	template<typename fieldType, typename ...types> FORCEINLINE constexpr auto get( CTuple<types...> &tuple ) { return tuple.template Get<fieldType>(); }
	// Deduction guide for constructing a tuple
	template<typename ...types>
	 std::tuple( CTuple<types...> const & ) -> std::tuple<types...>;
}

template<typename ...types> class CCompatibleTuple;

template <typename Type0_t>
class CCompatibleTuple<Type0_t>
{
public:
	Type0_t _0;
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t const &val0 )
	{
		_0 = val0;
	}
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t &&val0 )
	{
		_0 = val0;
	}
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 1 ) );
		if constexpr( nFieldID == 0)
		{
			return _0;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 1 ) );
		if constexpr( nFieldID == 0)
		{
			return _0;
		}
	}

	template<typename fieldType>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field type
	{
		if constexpr( std::is_same_v<fieldType, Type0_t> )
		{
			return _0;
		}
	}

	template<typename fieldType>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field type
	{
		if constexpr( std::is_same_v<fieldType, Type0_t> )
		{
			return _0;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t>() const
	// Convert to STL tuple
	{
		return { _0 };
	}

	FORCEINLINE operator std::tuple<Type0_t> &()
	// Convert to writable reference to std::tuple. **Warning**, bad idea to do this on a temporary value
	{
		return *(( std::tuple<Type0_t> * ) this );
	}

	FORCEINLINE auto operator<=>( CCompatibleTuple<Type0_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CCompatibleTuple<Type0_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t>
CCompatibleTuple( Type0_t arg0 ) -> CCompatibleTuple<Type0_t>;
template<typename ...types> class CCompatibleTuple;

template <typename Type0_t, typename Type1_t>
class CCompatibleTuple<Type0_t,Type1_t>
{
public:
	Type1_t _1;
	Type0_t _0;
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t const &val0, Type1_t const &val1 )
	{
		_0 = val0;
		_1 = val1;
	}
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t &&val0, Type1_t &&val1 )
	{
		_0 = val0;
		_1 = val1;
	}
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 2 ) );
		if constexpr( nFieldID == 0)
		{
			return _0;
		}
		if constexpr( nFieldID == 1)
		{
			return _1;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 2 ) );
		if constexpr( nFieldID == 0)
		{
			return _0;
		}
		if constexpr( nFieldID == 1)
		{
			return _1;
		}
	}

	template<typename fieldType>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field type
	{
		if constexpr( std::is_same_v<fieldType, Type0_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type1_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			return _1;
		}
	}

	template<typename fieldType>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field type
	{
		if constexpr( std::is_same_v<fieldType, Type0_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type1_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			return _1;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t>() const
	// Convert to STL tuple
	{
		return { _1, _0 };
	}

	FORCEINLINE operator std::tuple<Type0_t,Type1_t> &()
	// Convert to writable reference to std::tuple. **Warning**, bad idea to do this on a temporary value
	{
		return *(( std::tuple<Type0_t,Type1_t> * ) this );
	}

	FORCEINLINE auto operator<=>( CCompatibleTuple<Type0_t,Type1_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CCompatibleTuple<Type0_t,Type1_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t>
CCompatibleTuple( Type0_t arg0, Type1_t arg1 ) -> CCompatibleTuple<Type0_t,Type1_t>;
template<typename ...types> class CCompatibleTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t>
class CCompatibleTuple<Type0_t,Type1_t,Type2_t>
{
public:
	Type2_t _2;
	Type1_t _1;
	Type0_t _0;
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t const &val0, Type1_t const &val1, Type2_t const &val2 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
	}
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t &&val0, Type1_t &&val1, Type2_t &&val2 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
	}
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 3 ) );
		if constexpr( nFieldID == 0)
		{
			return _0;
		}
		if constexpr( nFieldID == 1)
		{
			return _1;
		}
		if constexpr( nFieldID == 2)
		{
			return _2;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 3 ) );
		if constexpr( nFieldID == 0)
		{
			return _0;
		}
		if constexpr( nFieldID == 1)
		{
			return _1;
		}
		if constexpr( nFieldID == 2)
		{
			return _2;
		}
	}

	template<typename fieldType>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field type
	{
		if constexpr( std::is_same_v<fieldType, Type0_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type1_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			return _2;
		}
	}

	template<typename fieldType>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field type
	{
		if constexpr( std::is_same_v<fieldType, Type0_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type1_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			return _2;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t>() const
	// Convert to STL tuple
	{
		return { _2, _1, _0 };
	}

	FORCEINLINE operator std::tuple<Type0_t,Type1_t,Type2_t> &()
	// Convert to writable reference to std::tuple. **Warning**, bad idea to do this on a temporary value
	{
		return *(( std::tuple<Type0_t,Type1_t,Type2_t> * ) this );
	}

	FORCEINLINE auto operator<=>( CCompatibleTuple<Type0_t,Type1_t,Type2_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CCompatibleTuple<Type0_t,Type1_t,Type2_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t>
CCompatibleTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2 ) -> CCompatibleTuple<Type0_t,Type1_t,Type2_t>;
// Override of std::get
namespace std
{
	template<int nFieldID, typename ...types> FORCEINLINE constexpr auto const & get( CCompatibleTuple<types...> const &tuple ) { return tuple.template Get<nFieldID>(); }
	template<int nFieldID, typename ...types> FORCEINLINE constexpr auto & get( CCompatibleTuple<types...> &tuple ) { return tuple.template Get<nFieldID>(); }
	template<typename fieldType, typename ...types> FORCEINLINE constexpr auto get( CCompatibleTuple<types...> const &tuple ) { return tuple.template Get<fieldType>(); }
	template<typename fieldType, typename ...types> FORCEINLINE constexpr auto get( CCompatibleTuple<types...> &tuple ) { return tuple.template Get<fieldType>(); }
	// Deduction guide for constructing a tuple
	template<typename ...types>
	 std::tuple( CCompatibleTuple<types...> const & ) -> std::tuple<types...>;
}

