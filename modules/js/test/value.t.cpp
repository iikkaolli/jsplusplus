// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "value.hpp"

TEST_CASE( "Basic construction", "[constructors]" )
{
  js::value_c Value1;
  REQUIRE( Value1.is_object() == true );
  REQUIRE( Value1.is_number() == false );
  REQUIRE( Value1.is_string() == false );

  js::value_c Value2 { 10 };
  REQUIRE( Value2.is_object() == false );
  REQUIRE( Value2.is_number() == true );
  REQUIRE( Value2.is_string() == false );
}

TEST_CASE( "Basic copy construction", "[constructors]")
{
  js::value_c Value1;
  js::value_c Value2{ Value1 };  
  REQUIRE( Value2.is_object() == true );
  REQUIRE( Value2.is_number() == false );
  REQUIRE( Value2.is_string() == false );
  REQUIRE( Value2 == nullptr );

  js::value_c Value3{10};
  js::value_c Value4{Value3};
  REQUIRE( Value4.is_object() == false );
  REQUIRE( Value4.is_number() == true );
  REQUIRE( Value4.is_string() == false );
  REQUIRE( Value4 == 10 );
  
}

TEST_CASE( "Basic copy assignment", "[constructors]")
{
  js::value_c Value1;
  js::value_c Value2;

  Value2 = Value1;
  REQUIRE( Value2.is_object() == true );
  REQUIRE( Value2.is_number() == false );
  REQUIRE( Value2.is_string() == false );
  REQUIRE( Value2 == nullptr );

  Value2 = 10;
  REQUIRE( Value2.is_object() == false );
  REQUIRE( Value2.is_number() == true );
  REQUIRE( Value2.is_string() == false );
  REQUIRE( Value2 == 10 );
}

TEST_CASE( "Basic comparison", "[compare]" )
{
  js::value_c Value1;
  REQUIRE( Value1 == nullptr );
  REQUIRE( nullptr == Value1 );

  js::value_c Value2{ 10 };
  REQUIRE( Value2 != nullptr );
  REQUIRE( nullptr != Value2 );
  REQUIRE( Value2 == 10 );
  REQUIRE( 10 == Value2 );
}
