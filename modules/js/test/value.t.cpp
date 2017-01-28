// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "value.hpp"

TEST_CASE( "Basic construction", "[constructors]" )
{
  js::value_c ValueDefault;
  REQUIRE( ValueDefault.is_object() == true );
  REQUIRE( ValueDefault.is_number() == false );
  REQUIRE( ValueDefault.is_string() == false );

  js::value_c ValueNull{ nullptr }; 
  REQUIRE( ValueNull.is_object() == true );
  REQUIRE( ValueNull.is_number() == false );
  REQUIRE( ValueNull.is_string() == false );

  js::value_c ValueInt{ 10 };
  REQUIRE( ValueInt.is_object() == false );
  REQUIRE( ValueInt.is_number() == true );
  REQUIRE( ValueInt.is_string() == false );

  js::value_c ValueDouble{ 20.0 };
  REQUIRE( ValueDouble.is_object() == false );
  REQUIRE( ValueDouble.is_number() == true );
  REQUIRE( ValueDouble.is_string() == false );
}

TEST_CASE( "Basic copy construction", "[constructors]")
{
  js::value_c ValueDefault;
  js::value_c CopyOfDefault{ ValueDefault };  
  REQUIRE( CopyOfDefault.is_object() == true );
  REQUIRE( CopyOfDefault.is_number() == false );
  REQUIRE( CopyOfDefault.is_string() == false );
  REQUIRE( CopyOfDefault == nullptr );

  js::value_c ValueNull{ nullptr };
  js::value_c CopyOfNull{ ValueNull };  
  REQUIRE( CopyOfNull.is_object() == true );
  REQUIRE( CopyOfNull.is_number() == false );
  REQUIRE( CopyOfNull.is_string() == false );
  REQUIRE( CopyOfNull == nullptr );

  js::value_c ValueInt{ 10 };
  js::value_c CopyOfInt{ ValueInt };
  REQUIRE( CopyOfInt.is_object() == false );
  REQUIRE( CopyOfInt.is_number() == true );
  REQUIRE( CopyOfInt.is_string() == false );
  REQUIRE( CopyOfInt == 10 );

  js::value_c ValueDouble{ 20.0 };
  js::value_c CopyOfDouble{ ValueDouble };
  REQUIRE( CopyOfDouble.is_object() == false );
  REQUIRE( CopyOfDouble.is_number() == true );
  REQUIRE( CopyOfDouble.is_string() == false );
  REQUIRE( CopyOfDouble == 20.0 );
  
}

TEST_CASE( "Basic copy assignment", "[constructors]")
{
  js::value_c TargetValue;

  TargetValue = nullptr;
  REQUIRE( TargetValue.is_object() == true );
  REQUIRE( TargetValue.is_number() == false );
  REQUIRE( TargetValue.is_string() == false );
  REQUIRE( TargetValue == nullptr );

  TargetValue = 10;
  REQUIRE( TargetValue.is_object() == false );
  REQUIRE( TargetValue.is_number() == true );
  REQUIRE( TargetValue.is_string() == false );
  REQUIRE( TargetValue == 10 );

  TargetValue = 20.0;
  REQUIRE( TargetValue.is_object() == false );
  REQUIRE( TargetValue.is_number() == true );
  REQUIRE( TargetValue.is_string() == false );
  REQUIRE( TargetValue == 20.0 );
}

TEST_CASE( "Basic comparison", "[compare]" )
{
  js::value_c ValueDefault;
  REQUIRE( ValueDefault == nullptr );
  REQUIRE( nullptr == ValueDefault );

  js::value_c ValueNull{ nullptr };
  REQUIRE( ValueNull == nullptr );
  REQUIRE( nullptr == ValueNull );

  js::value_c ValueInt{ 10 };
  REQUIRE( ValueInt != nullptr );
  REQUIRE( nullptr != ValueInt );
  REQUIRE( ValueInt == 10 );
  REQUIRE( 10 == ValueInt );
  REQUIRE( ValueInt != 100 );
  REQUIRE( 100 != ValueInt );

  js::value_c ValueDouble{ 20.0 };
  REQUIRE( ValueDouble != nullptr );
  REQUIRE( nullptr != ValueDouble );
  REQUIRE( ValueDouble == 20.0 );
  REQUIRE( 20.0 == ValueDouble );
  REQUIRE( ValueDouble != 20.1 );
  REQUIRE( 20.1 != ValueDouble );
}
