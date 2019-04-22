#include <catch2/catch.hpp>
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

TEST_CASE( "Add property pair", "[object]")
{
  js::object_c object;
  object.add_property( std::pair<std::string, js::value_c>("Foo", 10));
  REQUIRE( object.has_property("Foo") == true );
  REQUIRE( object["Foo"] == 10 );
}

TEST_CASE( "Get non existing value", "[object]" )
{
  js::object_c object;
  REQUIRE( object.has_property("Bar") == false );
  REQUIRE( object["Bar"] == nullptr );
}

TEST_CASE( "Get value", "[object]" )
{
  js::object_c object;
  object.add_property("Foo", js::value_c{10});
  REQUIRE( object.has_property("Foo") == true );
  REQUIRE( object["Foo"] == 10 );
}

TEST_CASE( "Set new property", "[object]")
{
  js::object_c object;
  object["fooNull"] = nullptr;
  REQUIRE( object.has_property("fooNull") == true );
  REQUIRE( object["fooNull"] == nullptr );

  object["fooInt"] = 10;
  REQUIRE( object.has_property("fooInt") == true );
  REQUIRE( object["fooInt"] == 10 );

  object["fooDouble"] = 1.0;
  REQUIRE( object.has_property("fooDouble") == true );
  REQUIRE( object["fooDouble"] == 1.0 );

  object["fooString1"] = "charPtr";
  REQUIRE( object.has_property("fooString1") == true );
  REQUIRE( object["fooString1"] == "charPtr" );

  object["fooString2"] = std::string{"string"};
  REQUIRE( object.has_property("fooString2") == true );
  REQUIRE( object["fooString2"] == "string" );
}

TEST_CASE( "Initialize object", "[object]")
{
  js::object_c object {
    {"fooNull", nullptr},
    {"fooInt", 10},
    {"fooDouble", 1.0},
    //{"fooString1", "charPtr"},
    {"fooString2", std::string{"string"}}
  };

  REQUIRE( object.has_property("fooNull") == true );
  REQUIRE( object["fooNull"] == nullptr );
  REQUIRE( object.has_property("fooInt") == true );
  REQUIRE( object["fooInt"] == 10 );
  REQUIRE( object.has_property("fooDouble") == true );
  REQUIRE( object["fooDouble"] == 1.0 );
  //REQUIRE( object.has_property("fooString1") == true );
  //REQUIRE( object["fooString1"] == "charPtr" );
  REQUIRE( object.has_property("fooString2") == true );
  REQUIRE( object["fooString2"] == "string" );
}
