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
template<typename ...types> class CTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t>
class CTuple<Type0_t,Type1_t,Type2_t,Type3_t>
{
public:
	Type0_t _0;
	Type1_t _1;
	Type2_t _2;
	Type3_t _3;
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 4 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 4 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			return _3;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			return _3;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t>() const
	// Convert to STL tuple
	{
		return { _0, _1, _2, _3 };
	}

	FORCEINLINE auto operator<=>( CTuple<Type0_t,Type1_t,Type2_t,Type3_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CTuple<Type0_t,Type1_t,Type2_t,Type3_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t>
CTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3 ) -> CTuple<Type0_t,Type1_t,Type2_t,Type3_t>;
template<typename ...types> class CTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t>
class CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t>
{
public:
	Type0_t _0;
	Type1_t _1;
	Type2_t _2;
	Type3_t _3;
	Type4_t _4;
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 5 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 5 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			return _4;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			return _4;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t>() const
	// Convert to STL tuple
	{
		return { _0, _1, _2, _3, _4 };
	}

	FORCEINLINE auto operator<=>( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t>
CTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4 ) -> CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t>;
template<typename ...types> class CTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t>
class CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t>
{
public:
	Type0_t _0;
	Type1_t _1;
	Type2_t _2;
	Type3_t _3;
	Type4_t _4;
	Type5_t _5;
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		_5 = std::get<5>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 6 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 6 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			return _5;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			return _5;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t>() const
	// Convert to STL tuple
	{
		return { _0, _1, _2, _3, _4, _5 };
	}

	FORCEINLINE auto operator<=>( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t>
CTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4, Type5_t arg5 ) -> CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t>;
template<typename ...types> class CTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t>
class CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t>
{
public:
	Type0_t _0;
	Type1_t _1;
	Type2_t _2;
	Type3_t _3;
	Type4_t _4;
	Type5_t _5;
	Type6_t _6;
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		_5 = std::get<5>( tuple );
		_6 = std::get<6>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 7 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 7 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			return _6;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			return _6;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t>() const
	// Convert to STL tuple
	{
		return { _0, _1, _2, _3, _4, _5, _6 };
	}

	FORCEINLINE auto operator<=>( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t>
CTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4, Type5_t arg5, Type6_t arg6 ) -> CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t>;
template<typename ...types> class CTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t>
class CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t>
{
public:
	Type0_t _0;
	Type1_t _1;
	Type2_t _2;
	Type3_t _3;
	Type4_t _4;
	Type5_t _5;
	Type6_t _6;
	Type7_t _7;
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		_5 = std::get<5>( tuple );
		_6 = std::get<6>( tuple );
		_7 = std::get<7>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 8 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 8 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			return _7;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			return _7;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t>() const
	// Convert to STL tuple
	{
		return { _0, _1, _2, _3, _4, _5, _6, _7 };
	}

	FORCEINLINE auto operator<=>( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t>
CTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4, Type5_t arg5, Type6_t arg6, Type7_t arg7 ) -> CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t>;
template<typename ...types> class CTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t>
class CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t>
{
public:
	Type0_t _0;
	Type1_t _1;
	Type2_t _2;
	Type3_t _3;
	Type4_t _4;
	Type5_t _5;
	Type6_t _6;
	Type7_t _7;
	Type8_t _8;
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		_5 = std::get<5>( tuple );
		_6 = std::get<6>( tuple );
		_7 = std::get<7>( tuple );
		_8 = std::get<8>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 9 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 9 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			return _8;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			return _8;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t>() const
	// Convert to STL tuple
	{
		return { _0, _1, _2, _3, _4, _5, _6, _7, _8 };
	}

	FORCEINLINE auto operator<=>( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t>
CTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4, Type5_t arg5, Type6_t arg6, Type7_t arg7, Type8_t arg8 ) -> CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t>;
template<typename ...types> class CTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t, typename Type9_t>
class CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t>
{
public:
	Type0_t _0;
	Type1_t _1;
	Type2_t _2;
	Type3_t _3;
	Type4_t _4;
	Type5_t _5;
	Type6_t _6;
	Type7_t _7;
	Type8_t _8;
	Type9_t _9;
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		_5 = std::get<5>( tuple );
		_6 = std::get<6>( tuple );
		_7 = std::get<7>( tuple );
		_8 = std::get<8>( tuple );
		_9 = std::get<9>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 10 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
		}
		if constexpr( nFieldID == 9)
		{
			return _9;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 10 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
		}
		if constexpr( nFieldID == 9)
		{
			return _9;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _8;
		}
		if constexpr( std::is_same_v<fieldType, Type9_t> )
		{
			return _9;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _8;
		}
		if constexpr( std::is_same_v<fieldType, Type9_t> )
		{
			return _9;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t>() const
	// Convert to STL tuple
	{
		return { _0, _1, _2, _3, _4, _5, _6, _7, _8, _9 };
	}

	FORCEINLINE auto operator<=>( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t, typename Type9_t>
CTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4, Type5_t arg5, Type6_t arg6, Type7_t arg7, Type8_t arg8, Type9_t arg9 ) -> CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t>;
template<typename ...types> class CTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t, typename Type9_t, typename Type10_t>
class CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t>
{
public:
	Type0_t _0;
	Type1_t _1;
	Type2_t _2;
	Type3_t _3;
	Type4_t _4;
	Type5_t _5;
	Type6_t _6;
	Type7_t _7;
	Type8_t _8;
	Type9_t _9;
	Type10_t _10;
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		_5 = std::get<5>( tuple );
		_6 = std::get<6>( tuple );
		_7 = std::get<7>( tuple );
		_8 = std::get<8>( tuple );
		_9 = std::get<9>( tuple );
		_10 = std::get<10>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 11 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
		}
		if constexpr( nFieldID == 9)
		{
			return _9;
		}
		if constexpr( nFieldID == 10)
		{
			return _10;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 11 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
		}
		if constexpr( nFieldID == 9)
		{
			return _9;
		}
		if constexpr( nFieldID == 10)
		{
			return _10;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _8;
		}
		if constexpr( std::is_same_v<fieldType, Type9_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _9;
		}
		if constexpr( std::is_same_v<fieldType, Type10_t> )
		{
			return _10;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _8;
		}
		if constexpr( std::is_same_v<fieldType, Type9_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _9;
		}
		if constexpr( std::is_same_v<fieldType, Type10_t> )
		{
			return _10;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t>() const
	// Convert to STL tuple
	{
		return { _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10 };
	}

	FORCEINLINE auto operator<=>( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t, typename Type9_t, typename Type10_t>
CTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4, Type5_t arg5, Type6_t arg6, Type7_t arg7, Type8_t arg8, Type9_t arg9, Type10_t arg10 ) -> CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t>;
template<typename ...types> class CTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t, typename Type9_t, typename Type10_t, typename Type11_t>
class CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t,Type11_t>
{
public:
	Type0_t _0;
	Type1_t _1;
	Type2_t _2;
	Type3_t _3;
	Type4_t _4;
	Type5_t _5;
	Type6_t _6;
	Type7_t _7;
	Type8_t _8;
	Type9_t _9;
	Type10_t _10;
	Type11_t _11;
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t,Type11_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		_5 = std::get<5>( tuple );
		_6 = std::get<6>( tuple );
		_7 = std::get<7>( tuple );
		_8 = std::get<8>( tuple );
		_9 = std::get<9>( tuple );
		_10 = std::get<10>( tuple );
		_11 = std::get<11>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 12 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
		}
		if constexpr( nFieldID == 9)
		{
			return _9;
		}
		if constexpr( nFieldID == 10)
		{
			return _10;
		}
		if constexpr( nFieldID == 11)
		{
			return _11;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 12 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
		}
		if constexpr( nFieldID == 9)
		{
			return _9;
		}
		if constexpr( nFieldID == 10)
		{
			return _10;
		}
		if constexpr( nFieldID == 11)
		{
			return _11;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _8;
		}
		if constexpr( std::is_same_v<fieldType, Type9_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _9;
		}
		if constexpr( std::is_same_v<fieldType, Type10_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _10;
		}
		if constexpr( std::is_same_v<fieldType, Type11_t> )
		{
			return _11;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _8;
		}
		if constexpr( std::is_same_v<fieldType, Type9_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _9;
		}
		if constexpr( std::is_same_v<fieldType, Type10_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _10;
		}
		if constexpr( std::is_same_v<fieldType, Type11_t> )
		{
			return _11;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t,Type11_t>() const
	// Convert to STL tuple
	{
		return { _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11 };
	}

	FORCEINLINE auto operator<=>( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t,Type11_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t,Type11_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t, typename Type9_t, typename Type10_t, typename Type11_t>
CTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4, Type5_t arg5, Type6_t arg6, Type7_t arg7, Type8_t arg8, Type9_t arg9, Type10_t arg10, Type11_t arg11 ) -> CTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t,Type11_t>;
// Override of std::get
namespace std
{
	template<int nFieldID, typename ...types> FORCEINLINE constexpr auto const & get( CTuple<types...> const &tuple ) { return tuple.template Get<nFieldID>(); }
	template<int nFieldID, typename ...types> FORCEINLINE constexpr auto & get( CTuple<types...> &tuple ) { return tuple.template Get<nFieldID>(); }
	template<typename fieldType, typename ...types> FORCEINLINE constexpr auto get( CTuple<types...> const &tuple ) { return tuple.template Get<fieldType>(); }
	template<typename fieldType, typename ...types> FORCEINLINE constexpr auto get( CTuple<types...> &tuple ) { return tuple.template Get<fieldType>(); }
	// Deduction guide for constructing a tuple
	template<typename ...types>
	    tuple( CTuple<types...> const & ) -> tuple<types...>;
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
template<typename ...types> class CCompatibleTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t>
class CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t>
{
public:
	Type3_t _3;
	Type2_t _2;
	Type1_t _1;
	Type0_t _0;
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t const &val0, Type1_t const &val1, Type2_t const &val2, Type3_t const &val3 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
	}
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t &&val0, Type1_t &&val1, Type2_t &&val2, Type3_t &&val3 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
	}
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 4 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 4 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			return _3;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			return _3;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t>() const
	// Convert to STL tuple
	{
		return { _3, _2, _1, _0 };
	}

	FORCEINLINE operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t> &()
	// Convert to writable reference to std::tuple. **Warning**, bad idea to do this on a temporary value
	{
		return *(( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t> * ) this );
	}

	FORCEINLINE auto operator<=>( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t>
CCompatibleTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3 ) -> CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t>;
template<typename ...types> class CCompatibleTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t>
class CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t>
{
public:
	Type4_t _4;
	Type3_t _3;
	Type2_t _2;
	Type1_t _1;
	Type0_t _0;
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t const &val0, Type1_t const &val1, Type2_t const &val2, Type3_t const &val3, Type4_t const &val4 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
	}
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t &&val0, Type1_t &&val1, Type2_t &&val2, Type3_t &&val3, Type4_t &&val4 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
	}
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 5 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 5 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			return _4;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			return _4;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t>() const
	// Convert to STL tuple
	{
		return { _4, _3, _2, _1, _0 };
	}

	FORCEINLINE operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t> &()
	// Convert to writable reference to std::tuple. **Warning**, bad idea to do this on a temporary value
	{
		return *(( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t> * ) this );
	}

	FORCEINLINE auto operator<=>( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t>
CCompatibleTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4 ) -> CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t>;
template<typename ...types> class CCompatibleTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t>
class CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t>
{
public:
	Type5_t _5;
	Type4_t _4;
	Type3_t _3;
	Type2_t _2;
	Type1_t _1;
	Type0_t _0;
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t const &val0, Type1_t const &val1, Type2_t const &val2, Type3_t const &val3, Type4_t const &val4, Type5_t const &val5 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
		_5 = val5;
	}
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t &&val0, Type1_t &&val1, Type2_t &&val2, Type3_t &&val3, Type4_t &&val4, Type5_t &&val5 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
		_5 = val5;
	}
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		_5 = std::get<5>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 6 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 6 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			return _5;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			return _5;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t>() const
	// Convert to STL tuple
	{
		return { _5, _4, _3, _2, _1, _0 };
	}

	FORCEINLINE operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t> &()
	// Convert to writable reference to std::tuple. **Warning**, bad idea to do this on a temporary value
	{
		return *(( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t> * ) this );
	}

	FORCEINLINE auto operator<=>( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t>
CCompatibleTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4, Type5_t arg5 ) -> CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t>;
template<typename ...types> class CCompatibleTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t>
class CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t>
{
public:
	Type6_t _6;
	Type5_t _5;
	Type4_t _4;
	Type3_t _3;
	Type2_t _2;
	Type1_t _1;
	Type0_t _0;
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t const &val0, Type1_t const &val1, Type2_t const &val2, Type3_t const &val3, Type4_t const &val4, Type5_t const &val5, Type6_t const &val6 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
		_5 = val5;
		_6 = val6;
	}
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t &&val0, Type1_t &&val1, Type2_t &&val2, Type3_t &&val3, Type4_t &&val4, Type5_t &&val5, Type6_t &&val6 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
		_5 = val5;
		_6 = val6;
	}
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		_5 = std::get<5>( tuple );
		_6 = std::get<6>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 7 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 7 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			return _6;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			return _6;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t>() const
	// Convert to STL tuple
	{
		return { _6, _5, _4, _3, _2, _1, _0 };
	}

	FORCEINLINE operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t> &()
	// Convert to writable reference to std::tuple. **Warning**, bad idea to do this on a temporary value
	{
		return *(( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t> * ) this );
	}

	FORCEINLINE auto operator<=>( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t>
CCompatibleTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4, Type5_t arg5, Type6_t arg6 ) -> CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t>;
template<typename ...types> class CCompatibleTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t>
class CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t>
{
public:
	Type7_t _7;
	Type6_t _6;
	Type5_t _5;
	Type4_t _4;
	Type3_t _3;
	Type2_t _2;
	Type1_t _1;
	Type0_t _0;
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t const &val0, Type1_t const &val1, Type2_t const &val2, Type3_t const &val3, Type4_t const &val4, Type5_t const &val5, Type6_t const &val6, Type7_t const &val7 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
		_5 = val5;
		_6 = val6;
		_7 = val7;
	}
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t &&val0, Type1_t &&val1, Type2_t &&val2, Type3_t &&val3, Type4_t &&val4, Type5_t &&val5, Type6_t &&val6, Type7_t &&val7 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
		_5 = val5;
		_6 = val6;
		_7 = val7;
	}
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		_5 = std::get<5>( tuple );
		_6 = std::get<6>( tuple );
		_7 = std::get<7>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 8 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 8 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			return _7;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			return _7;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t>() const
	// Convert to STL tuple
	{
		return { _7, _6, _5, _4, _3, _2, _1, _0 };
	}

	FORCEINLINE operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t> &()
	// Convert to writable reference to std::tuple. **Warning**, bad idea to do this on a temporary value
	{
		return *(( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t> * ) this );
	}

	FORCEINLINE auto operator<=>( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t>
CCompatibleTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4, Type5_t arg5, Type6_t arg6, Type7_t arg7 ) -> CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t>;
template<typename ...types> class CCompatibleTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t>
class CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t>
{
public:
	Type8_t _8;
	Type7_t _7;
	Type6_t _6;
	Type5_t _5;
	Type4_t _4;
	Type3_t _3;
	Type2_t _2;
	Type1_t _1;
	Type0_t _0;
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t const &val0, Type1_t const &val1, Type2_t const &val2, Type3_t const &val3, Type4_t const &val4, Type5_t const &val5, Type6_t const &val6, Type7_t const &val7, Type8_t const &val8 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
		_5 = val5;
		_6 = val6;
		_7 = val7;
		_8 = val8;
	}
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t &&val0, Type1_t &&val1, Type2_t &&val2, Type3_t &&val3, Type4_t &&val4, Type5_t &&val5, Type6_t &&val6, Type7_t &&val7, Type8_t &&val8 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
		_5 = val5;
		_6 = val6;
		_7 = val7;
		_8 = val8;
	}
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		_5 = std::get<5>( tuple );
		_6 = std::get<6>( tuple );
		_7 = std::get<7>( tuple );
		_8 = std::get<8>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 9 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 9 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			return _8;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			return _8;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t>() const
	// Convert to STL tuple
	{
		return { _8, _7, _6, _5, _4, _3, _2, _1, _0 };
	}

	FORCEINLINE operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t> &()
	// Convert to writable reference to std::tuple. **Warning**, bad idea to do this on a temporary value
	{
		return *(( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t> * ) this );
	}

	FORCEINLINE auto operator<=>( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t>
CCompatibleTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4, Type5_t arg5, Type6_t arg6, Type7_t arg7, Type8_t arg8 ) -> CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t>;
template<typename ...types> class CCompatibleTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t, typename Type9_t>
class CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t>
{
public:
	Type9_t _9;
	Type8_t _8;
	Type7_t _7;
	Type6_t _6;
	Type5_t _5;
	Type4_t _4;
	Type3_t _3;
	Type2_t _2;
	Type1_t _1;
	Type0_t _0;
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t const &val0, Type1_t const &val1, Type2_t const &val2, Type3_t const &val3, Type4_t const &val4, Type5_t const &val5, Type6_t const &val6, Type7_t const &val7, Type8_t const &val8, Type9_t const &val9 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
		_5 = val5;
		_6 = val6;
		_7 = val7;
		_8 = val8;
		_9 = val9;
	}
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t &&val0, Type1_t &&val1, Type2_t &&val2, Type3_t &&val3, Type4_t &&val4, Type5_t &&val5, Type6_t &&val6, Type7_t &&val7, Type8_t &&val8, Type9_t &&val9 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
		_5 = val5;
		_6 = val6;
		_7 = val7;
		_8 = val8;
		_9 = val9;
	}
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		_5 = std::get<5>( tuple );
		_6 = std::get<6>( tuple );
		_7 = std::get<7>( tuple );
		_8 = std::get<8>( tuple );
		_9 = std::get<9>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 10 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
		}
		if constexpr( nFieldID == 9)
		{
			return _9;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 10 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
		}
		if constexpr( nFieldID == 9)
		{
			return _9;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _8;
		}
		if constexpr( std::is_same_v<fieldType, Type9_t> )
		{
			return _9;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			return _8;
		}
		if constexpr( std::is_same_v<fieldType, Type9_t> )
		{
			return _9;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t>() const
	// Convert to STL tuple
	{
		return { _9, _8, _7, _6, _5, _4, _3, _2, _1, _0 };
	}

	FORCEINLINE operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t> &()
	// Convert to writable reference to std::tuple. **Warning**, bad idea to do this on a temporary value
	{
		return *(( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t> * ) this );
	}

	FORCEINLINE auto operator<=>( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t, typename Type9_t>
CCompatibleTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4, Type5_t arg5, Type6_t arg6, Type7_t arg7, Type8_t arg8, Type9_t arg9 ) -> CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t>;
template<typename ...types> class CCompatibleTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t, typename Type9_t, typename Type10_t>
class CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t>
{
public:
	Type10_t _10;
	Type9_t _9;
	Type8_t _8;
	Type7_t _7;
	Type6_t _6;
	Type5_t _5;
	Type4_t _4;
	Type3_t _3;
	Type2_t _2;
	Type1_t _1;
	Type0_t _0;
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t const &val0, Type1_t const &val1, Type2_t const &val2, Type3_t const &val3, Type4_t const &val4, Type5_t const &val5, Type6_t const &val6, Type7_t const &val7, Type8_t const &val8, Type9_t const &val9, Type10_t const &val10 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
		_5 = val5;
		_6 = val6;
		_7 = val7;
		_8 = val8;
		_9 = val9;
		_10 = val10;
	}
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t &&val0, Type1_t &&val1, Type2_t &&val2, Type3_t &&val3, Type4_t &&val4, Type5_t &&val5, Type6_t &&val6, Type7_t &&val7, Type8_t &&val8, Type9_t &&val9, Type10_t &&val10 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
		_5 = val5;
		_6 = val6;
		_7 = val7;
		_8 = val8;
		_9 = val9;
		_10 = val10;
	}
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		_5 = std::get<5>( tuple );
		_6 = std::get<6>( tuple );
		_7 = std::get<7>( tuple );
		_8 = std::get<8>( tuple );
		_9 = std::get<9>( tuple );
		_10 = std::get<10>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 11 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
		}
		if constexpr( nFieldID == 9)
		{
			return _9;
		}
		if constexpr( nFieldID == 10)
		{
			return _10;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 11 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
		}
		if constexpr( nFieldID == 9)
		{
			return _9;
		}
		if constexpr( nFieldID == 10)
		{
			return _10;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _8;
		}
		if constexpr( std::is_same_v<fieldType, Type9_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _9;
		}
		if constexpr( std::is_same_v<fieldType, Type10_t> )
		{
			return _10;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _8;
		}
		if constexpr( std::is_same_v<fieldType, Type9_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			return _9;
		}
		if constexpr( std::is_same_v<fieldType, Type10_t> )
		{
			return _10;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t>() const
	// Convert to STL tuple
	{
		return { _10, _9, _8, _7, _6, _5, _4, _3, _2, _1, _0 };
	}

	FORCEINLINE operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t> &()
	// Convert to writable reference to std::tuple. **Warning**, bad idea to do this on a temporary value
	{
		return *(( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t> * ) this );
	}

	FORCEINLINE auto operator<=>( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t, typename Type9_t, typename Type10_t>
CCompatibleTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4, Type5_t arg5, Type6_t arg6, Type7_t arg7, Type8_t arg8, Type9_t arg9, Type10_t arg10 ) -> CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t>;
template<typename ...types> class CCompatibleTuple;

template <typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t, typename Type9_t, typename Type10_t, typename Type11_t>
class CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t,Type11_t>
{
public:
	Type11_t _11;
	Type10_t _10;
	Type9_t _9;
	Type8_t _8;
	Type7_t _7;
	Type6_t _6;
	Type5_t _5;
	Type4_t _4;
	Type3_t _3;
	Type2_t _2;
	Type1_t _1;
	Type0_t _0;
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t const &val0, Type1_t const &val1, Type2_t const &val2, Type3_t const &val3, Type4_t const &val4, Type5_t const &val5, Type6_t const &val6, Type7_t const &val7, Type8_t const &val8, Type9_t const &val9, Type10_t const &val10, Type11_t const &val11 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
		_5 = val5;
		_6 = val6;
		_7 = val7;
		_8 = val8;
		_9 = val9;
		_10 = val10;
		_11 = val11;
	}
	constexpr  FORCEINLINE CCompatibleTuple( Type0_t &&val0, Type1_t &&val1, Type2_t &&val2, Type3_t &&val3, Type4_t &&val4, Type5_t &&val5, Type6_t &&val6, Type7_t &&val7, Type8_t &&val8, Type9_t &&val9, Type10_t &&val10, Type11_t &&val11 )
	{
		_0 = val0;
		_1 = val1;
		_2 = val2;
		_3 = val3;
		_4 = val4;
		_5 = val5;
		_6 = val6;
		_7 = val7;
		_8 = val8;
		_9 = val9;
		_10 = val10;
		_11 = val11;
	}
	
	FORCEINLINE constexpr auto & operator=( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t,Type11_t> const &tuple )
	// Assignment from STL tuple
	{
		_0 = std::get<0>( tuple );
		_1 = std::get<1>( tuple );
		_2 = std::get<2>( tuple );
		_3 = std::get<3>( tuple );
		_4 = std::get<4>( tuple );
		_5 = std::get<5>( tuple );
		_6 = std::get<6>( tuple );
		_7 = std::get<7>( tuple );
		_8 = std::get<8>( tuple );
		_9 = std::get<9>( tuple );
		_10 = std::get<10>( tuple );
		_11 = std::get<11>( tuple );
		return *this;
	}
	template<int nFieldID>
	FORCEINLINE constexpr auto & Get() 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 12 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
		}
		if constexpr( nFieldID == 9)
		{
			return _9;
		}
		if constexpr( nFieldID == 10)
		{
			return _10;
		}
		if constexpr( nFieldID == 11)
		{
			return _11;
		}
	}

	template<int nFieldID>
	FORCEINLINE constexpr auto const & Get() const 
	// Member get function by field index
	{
		static_assert( ( nFieldID >= 0 ) && ( nFieldID < 12 ) );
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
		if constexpr( nFieldID == 3)
		{
			return _3;
		}
		if constexpr( nFieldID == 4)
		{
			return _4;
		}
		if constexpr( nFieldID == 5)
		{
			return _5;
		}
		if constexpr( nFieldID == 6)
		{
			return _6;
		}
		if constexpr( nFieldID == 7)
		{
			return _7;
		}
		if constexpr( nFieldID == 8)
		{
			return _8;
		}
		if constexpr( nFieldID == 9)
		{
			return _9;
		}
		if constexpr( nFieldID == 10)
		{
			return _10;
		}
		if constexpr( nFieldID == 11)
		{
			return _11;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _8;
		}
		if constexpr( std::is_same_v<fieldType, Type9_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _9;
		}
		if constexpr( std::is_same_v<fieldType, Type10_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _10;
		}
		if constexpr( std::is_same_v<fieldType, Type11_t> )
		{
			return _11;
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
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _0;
		}
		if constexpr( std::is_same_v<fieldType, Type1_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type2_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _1;
		}
		if constexpr( std::is_same_v<fieldType, Type2_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type3_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _2;
		}
		if constexpr( std::is_same_v<fieldType, Type3_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type4_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _3;
		}
		if constexpr( std::is_same_v<fieldType, Type4_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type5_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _4;
		}
		if constexpr( std::is_same_v<fieldType, Type5_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type6_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _5;
		}
		if constexpr( std::is_same_v<fieldType, Type6_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type7_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _6;
		}
		if constexpr( std::is_same_v<fieldType, Type7_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type8_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _7;
		}
		if constexpr( std::is_same_v<fieldType, Type8_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type9_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _8;
		}
		if constexpr( std::is_same_v<fieldType, Type9_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type10_t>, "Duplicate types in Get<type>" );
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _9;
		}
		if constexpr( std::is_same_v<fieldType, Type10_t> )
		{
			static_assert( ! std::is_same_v<fieldType, Type11_t>, "Duplicate types in Get<type>" );
			return _10;
		}
		if constexpr( std::is_same_v<fieldType, Type11_t> )
		{
			return _11;
		}
	}

	FORCEINLINE constexpr operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t,Type11_t>() const
	// Convert to STL tuple
	{
		return { _11, _10, _9, _8, _7, _6, _5, _4, _3, _2, _1, _0 };
	}

	FORCEINLINE operator std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t,Type11_t> &()
	// Convert to writable reference to std::tuple. **Warning**, bad idea to do this on a temporary value
	{
		return *(( std::tuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t,Type11_t> * ) this );
	}

	FORCEINLINE auto operator<=>( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t,Type11_t> const &other ) const = default;
	// spaceship comparison operator

	FORCEINLINE void swap( CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t,Type11_t> &other )
	// member swap
	{
		std::swap( *this, other );
	}
};

// Deduction guide:
template<typename Type0_t, typename Type1_t, typename Type2_t, typename Type3_t, typename Type4_t, typename Type5_t, typename Type6_t, typename Type7_t, typename Type8_t, typename Type9_t, typename Type10_t, typename Type11_t>
CCompatibleTuple( Type0_t arg0, Type1_t arg1, Type2_t arg2, Type3_t arg3, Type4_t arg4, Type5_t arg5, Type6_t arg6, Type7_t arg7, Type8_t arg8, Type9_t arg9, Type10_t arg10, Type11_t arg11 ) -> CCompatibleTuple<Type0_t,Type1_t,Type2_t,Type3_t,Type4_t,Type5_t,Type6_t,Type7_t,Type8_t,Type9_t,Type10_t,Type11_t>;
// Override of std::get
namespace std
{
	template<int nFieldID, typename ...types> FORCEINLINE constexpr auto const & get( CCompatibleTuple<types...> const &tuple ) { return tuple.template Get<nFieldID>(); }
	template<int nFieldID, typename ...types> FORCEINLINE constexpr auto & get( CCompatibleTuple<types...> &tuple ) { return tuple.template Get<nFieldID>(); }
	template<typename fieldType, typename ...types> FORCEINLINE constexpr auto get( CCompatibleTuple<types...> const &tuple ) { return tuple.template Get<fieldType>(); }
	template<typename fieldType, typename ...types> FORCEINLINE constexpr auto get( CCompatibleTuple<types...> &tuple ) { return tuple.template Get<fieldType>(); }
	// Deduction guide for constructing a tuple
	template<typename ...types>
	    tuple( CCompatibleTuple<types...> const & ) -> tuple<types...>;
}
