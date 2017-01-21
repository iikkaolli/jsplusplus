#include "value.hpp"

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Basic construction", "[constructors]" )
{
  js::value Value1;
  REQUIRE( Value1.is_object() == true );
  REQUIRE( Value1.is_number() == false );
  REQUIRE( Value1.is_string() == false );
}
