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

  js::value_c ValueString{ "Foo" };
  REQUIRE( ValueString.is_object() == false );
  REQUIRE( ValueString.is_number() == false );
  REQUIRE( ValueString.is_string() == true );
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
  
  js::value_c ValueString{ "Foo" };
  js::value_c CopyOfString{ ValueString };
  REQUIRE( CopyOfString.is_object() == false );
  REQUIRE( CopyOfString.is_number() == false );
  REQUIRE( CopyOfString.is_string() == true );
  REQUIRE( CopyOfString == "Foo" );
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

  TargetValue = "Foo";
  REQUIRE( TargetValue.is_object() == false );
  REQUIRE( TargetValue.is_number() == false );
  REQUIRE( TargetValue.is_string() == true );
  REQUIRE( TargetValue == "Foo" );
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

  js::value_c ValueString{ "Foo" };
  REQUIRE( ValueString != nullptr );
  REQUIRE( nullptr != ValueString );
  REQUIRE( ValueString == "Foo" );
  REQUIRE( "Foo" == ValueString );
  REQUIRE( ValueString != "Bar" );
  REQUIRE( "Bar" != ValueString );
}

TEST_CASE( "Basic empty value equality comparison", "[compare]" )
{
  js::value_c ValueInt1{10};
  js::value_c ValueInt2{10};
  js::value_c ValueInt3{20};
  js::value_c ValueDouble1{10.0};
  js::value_c ValueDouble2{10.0};
  js::value_c ValueDouble3{20.0};
  js::value_c ValueString1{"10"};
  js::value_c ValueString2{"10"};
  js::value_c ValueString3{"20"};
  js::value_c ValueString4{"10.0"};
  js::value_c ValueString5{"10.1"};

  REQUIRE( (js::EmptyValue == js::EmptyValue) == true );
  REQUIRE( (js::EmptyValue == ValueInt1) == false );
  REQUIRE( (js::EmptyValue == ValueDouble1) == false );
  REQUIRE( (js::EmptyValue == ValueString1) == false );
}

TEST_CASE( "Basic int value equality comparison", "[compare]" )
{
  js::value_c ValueInt1{10};
  js::value_c ValueInt2{10};
  js::value_c ValueInt3{20};
  js::value_c ValueDouble1{10.0};
  js::value_c ValueDouble2{10.0};
  js::value_c ValueDouble3{20.0};
  js::value_c ValueString1{"10"};
  js::value_c ValueString2{"10"};
  js::value_c ValueString3{"20"};
  js::value_c ValueString4{"10.0"};
  js::value_c ValueString5{"10.1"};
  js::value_c ValueString6{"abc"};
  js::value_c ValueString7{"10abc"};
  js::value_c ValueString8{"abc10"};

  REQUIRE( (ValueInt1 == js::EmptyValue) == false );
  REQUIRE( (ValueInt1 == ValueInt2) == true );
  REQUIRE( (ValueInt1 == ValueInt3) == false );
  REQUIRE( (ValueInt1 == ValueDouble2) == true );
  REQUIRE( (ValueInt1 == ValueDouble3) == false );
  REQUIRE( (ValueInt1 == ValueString2) == true );
  REQUIRE( (ValueInt1 == ValueString3) == false );
  REQUIRE( (ValueInt1 == ValueString4) == false );
  REQUIRE( (ValueInt1 == ValueString5) == false );
  REQUIRE( (ValueInt1 == ValueString6) == false );
  REQUIRE( (ValueInt1 == ValueString7) == false );
  REQUIRE( (ValueInt1 == ValueString8) == false );
}

TEST_CASE( "Basic double value equality comparison", "[compare]" )
{
  js::value_c ValueInt1{10};
  js::value_c ValueInt2{10};
  js::value_c ValueInt3{20};
  js::value_c ValueDouble1{10.0};
  js::value_c ValueDouble2{10.0};
  js::value_c ValueDouble3{20.0};
  js::value_c ValueString1{"10"};
  js::value_c ValueString2{"10"};
  js::value_c ValueString3{"20"};
  js::value_c ValueString4{"10.0"};
  js::value_c ValueString5{"10.1"};
  js::value_c ValueString6{"abc"};
  js::value_c ValueString7{"10abc"};
  js::value_c ValueString8{"abc10"};

  REQUIRE( (ValueDouble1 == js::EmptyValue) == false );
  REQUIRE( (ValueDouble1 == ValueInt2) == true );
  REQUIRE( (ValueDouble1 == ValueInt3) == false );
  REQUIRE( (ValueDouble1 == ValueDouble2) == true );
  REQUIRE( (ValueDouble1 == ValueDouble3) == false );
  REQUIRE( (ValueDouble1 == ValueString2) == true );
  REQUIRE( (ValueDouble1 == ValueString3) == false );
  REQUIRE( (ValueDouble1 == ValueString4) == true );
  REQUIRE( (ValueDouble1 == ValueString5) == false );
  REQUIRE( (ValueDouble1 == ValueString6) == false );
  REQUIRE( (ValueDouble1 == ValueString7) == false );
  REQUIRE( (ValueDouble1 == ValueString8) == false );
}
 
TEST_CASE( "Basic string value equality comparison", "[compare]" )
{
  js::value_c ValueInt1{10};
  js::value_c ValueInt2{10};
  js::value_c ValueInt3{20};
  js::value_c ValueDouble1{10.0};
  js::value_c ValueDouble2{10.0};
  js::value_c ValueDouble3{20.0};
  js::value_c ValueString1{"10"};
  js::value_c ValueString2{"10"};
  js::value_c ValueString3{"20"};
  js::value_c ValueString4{"10.0"};
  js::value_c ValueString5{"10.1"};
  js::value_c ValueString6{"abc"};
  js::value_c ValueString7{"10abc"};
  js::value_c ValueString8{"abc10"};

  REQUIRE( (ValueString1 == js::EmptyValue) == false );
  REQUIRE( (ValueString1 == ValueInt2) == true );
  REQUIRE( (ValueString1 == ValueInt3) == false );
  REQUIRE( (ValueString1 == ValueDouble2) == true );
  REQUIRE( (ValueString1 == ValueDouble3) == false );
  REQUIRE( (ValueString1 == ValueString2) == true );
  REQUIRE( (ValueString1 == ValueString3) == false );
  REQUIRE( (ValueString6 == ValueInt1) == false );
  REQUIRE( (ValueString6 == ValueDouble1) == false );
  REQUIRE( (ValueString7 == ValueInt1) == false );
  REQUIRE( (ValueString7 == ValueDouble1) == false );
  REQUIRE( (ValueString8 == ValueInt1) == false );
  REQUIRE( (ValueString8 == ValueDouble1) == false );
}
