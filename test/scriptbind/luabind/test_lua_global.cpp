#include "test_lua_common.h"


namespace {


GTEST(global)
{
	using namespace cpgf;
	using namespace testscript;

	GScopedPointer<TestLuaContext> context(createLuaContext());

	GScopedInterface<IMetaClass> metaClass(context->getService()->findClassByName("testscript::TestData"));
	GCHECK(metaClass);
	
	GScopedPointer<TestData> dataLib(new TestData);
	GScopedPointer<TestData> dataApi(new TestData);
	dataLib->x = 10;
	dataLib->name = "abc";
	dataApi->x = 10;
	dataApi->name = "abc";

	GScopedInterface<IScriptObject> bindingApi(context->getBindingApi());

	context->getBindingLib()->bindObject("data", dataLib.get(), metaClass.get(), false);
	
	bindingApi->bindObject("data", dataApi.get(), metaClass.get(), false);
	
	QASSERT(data.x == 10)
	QASSERT(data.name == "abc")
	QDO(data.x = data.x + 1)

	GEQUAL(dataLib->x, 11);
	GEQUAL(dataApi->x, 11);
	
	context->getBindingLib()->nullifyValue("data");
	bindingApi->nullifyValue("data");
	QASSERT(data == nil)
}




}
