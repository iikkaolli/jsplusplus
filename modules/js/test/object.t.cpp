#include "catch.hpp"
#include "object.hpp"
#include "value.hpp"

TEST_CASE( "Empty object", "[object]" )
{
  js::object_c object;

  REQUIRE( object.has_property("Foo") == false );
}

TEST_CASE( "Add property", "[object]" )
{
  js::object_c object;
  object.add_property("Foo", js::value_c{10});
  REQUIRE( object.has_property("Foo") == true );
  REQUIRE( object.has_property("Bar") == false );
}
