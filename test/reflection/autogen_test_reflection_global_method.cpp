// Auto generated test code
// Don't modify manually.

#include "test_reflection_common.h"

#define CLASS void
#define NAME_CLASS GPP_STRINGIZE(CLASS)

#define METHOD(f) pointerAssign(method, metaClass->getMethod(# f))

using namespace std;
using namespace cpgf;

namespace Test_GlobalMethod { namespace {



	int fieldMethodInt;
	string fieldMethodString;




	int methodGetInt() {
		return fieldMethodInt;
	}

	 void methodAddInt(int n) {
		fieldMethodInt += n;
	}

	string & methodRefString() {
		return fieldMethodString;
	}

	string methodConcatString(const string & append) {
		fieldMethodString = fieldMethodString + append;
		return fieldMethodString;
	}

	CLASS_DATA methodAddData(CLASS_DATA data) {
		data.s = data.s + fieldMethodString;
		data.i += fieldMethodInt;

		return data;
	}

	void methodMakeData(CLASS_DATA & data) {
		data.s = fieldMethodString;
		data.i = fieldMethodInt;
	}

	void methodMakeDataByPointer(CLASS_DATA * data) {
		data->s = fieldMethodString;
		data->i = fieldMethodInt;
	}

	void methodManyParams(
		char c,	int i, long long ll,
		double d, string s, const char * pc,
		CLASS_DATA data
	) {
		GEQUAL(c, 'A');
		GEQUAL(i, 38);
		GEQUAL(ll, 9876532198765321LL);
		GNEAR(d, 1.99, 0.0001);
		GEQUAL(s, "Many");
		GEQUAL(string(pc), string("Too Many"));
		GEQUAL(data.s, "Data");
		GEQUAL(data.i, 8);
	}

	int methodSum(const GMetaVariadicParam * params) {
		int total = 0;
		for(size_t i = 0; i < params->paramCount; ++i) {
			total += cpgf::fromVariant<int>(*(params->params[i]));
		}

		return total;
	}



GMETA_DEFINE_GLOBAL() {
	GMETA_QUALIFIED_METHOD(methodGetInt);
	GMETA_QUALIFIED_METHOD(methodAddInt);
	GMETA_QUALIFIED_METHOD(methodRefString);
	GMETA_QUALIFIED_METHOD(methodConcatString);
	GMETA_QUALIFIED_METHOD(methodAddData);
	GMETA_QUALIFIED_METHOD(methodMakeData);
	GMETA_QUALIFIED_METHOD(methodMakeDataByPointer);
	GMETA_QUALIFIED_METHOD(methodManyParams);
	GMETA_QUALIFIED_METHOD(methodSum);
}


GTEST(Lib_Exists)
{
	const GMetaClass * metaClass = getGlobalMetaClass();
	GCHECK(metaClass);
	
	const GMetaMethod * method;

	METHOD(methodGetInt);
	GCHECK(method);

	METHOD(methodAddInt);
	GCHECK(method);

	METHOD(methodRefString);
	GCHECK(method);

	METHOD(methodConcatString);
	GCHECK(method);

	METHOD(methodAddData);
	GCHECK(method);

	METHOD(methodMakeData);
	GCHECK(method);

	METHOD(methodMakeDataByPointer);
	GCHECK(method);

	METHOD(methodManyParams);
	GCHECK(method);

	METHOD(methodSum);
	GCHECK(method);
}


GTEST(API_Exists)
{
	GMetaScopedPointer<IMetaService> service(createMetaService());
	GCHECK(service);

	GMetaScopedPointer<IMetaClass> metaClass(service->getGlobalMetaClass());
	GCHECK(metaClass);

	GMetaScopedPointer<IMetaMethod> method;

	METHOD(methodGetInt);
	GCHECK(method);

	METHOD(methodAddInt);
	GCHECK(method);

	METHOD(methodRefString);
	GCHECK(method);

	METHOD(methodConcatString);
	GCHECK(method);

	METHOD(methodAddData);
	GCHECK(method);

	METHOD(methodMakeData);
	GCHECK(method);

	METHOD(methodMakeDataByPointer);
	GCHECK(method);

	METHOD(methodManyParams);
	GCHECK(method);

	METHOD(methodSum);
	GCHECK(method);
}


GTEST(Lib_ResultType)
{
	const GMetaClass * metaClass = getGlobalMetaClass();
	GCHECK(metaClass);
	
	const GMetaMethod * method;

	METHOD(methodGetInt);
	GEQUAL(method->getResultType(), createMetaType<int>());
	GCHECK(method->hasResult());

	METHOD(methodAddInt);
	GEQUAL(method->getResultType(), createMetaType<void>());
	GCHECK(! method->hasResult());

	METHOD(methodRefString);
	GEQUAL(method->getResultType(), createMetaType<string &>());
	GCHECK(method->hasResult());

	METHOD(methodConcatString);
	GEQUAL(method->getResultType(), createMetaType<string>());
	GCHECK(method->hasResult());

	METHOD(methodAddData);
	GEQUAL(method->getResultType(), createMetaType<CLASS_DATA>());
	GCHECK(method->hasResult());

	METHOD(methodMakeData);
	GEQUAL(method->getResultType(), createMetaType<void>());
	GCHECK(! method->hasResult());

	METHOD(methodMakeDataByPointer);
	GEQUAL(method->getResultType(), createMetaType<void>());
	GCHECK(! method->hasResult());

	METHOD(methodManyParams);
	GEQUAL(method->getResultType(), createMetaType<void>());
	GCHECK(! method->hasResult());

	METHOD(methodSum);
	GEQUAL(method->getResultType(), createMetaType<int>());
	GCHECK(method->hasResult());
}


GTEST(Lib_ParamType)
{
	const GMetaClass * metaClass = getGlobalMetaClass();
	GCHECK(metaClass);
	
	const GMetaMethod * method;

	METHOD(methodGetInt);
	GCHECK(! method->isVariadic());
	GEQUAL(method->getParamCount(), 0);

	METHOD(methodAddInt);
	GCHECK(! method->isVariadic());
	GEQUAL(method->getParamCount(), 1);
	GEQUAL(method->getParamType(0), createMetaType<int>());

	METHOD(methodRefString);
	GCHECK(! method->isVariadic());
	GEQUAL(method->getParamCount(), 0);

	METHOD(methodConcatString);
	GCHECK(! method->isVariadic());
	GEQUAL(method->getParamCount(), 1);
	GEQUAL(method->getParamType(0), createMetaType<string>());

	METHOD(methodAddData);
	GCHECK(! method->isVariadic());
	GEQUAL(method->getParamCount(), 1);
	GEQUAL(method->getParamType(0), createMetaType<CLASS_DATA>());

	METHOD(methodMakeData);
	GCHECK(! method->isVariadic());
	GEQUAL(method->getParamCount(), 1);
	GEQUAL(method->getParamType(0), createMetaType<CLASS_DATA>());

	METHOD(methodMakeDataByPointer);
	GCHECK(! method->isVariadic());
	GEQUAL(method->getParamCount(), 1);
	GEQUAL(method->getParamType(0), createMetaType<CLASS_DATA *>());

	METHOD(methodManyParams);
	GCHECK(! method->isVariadic());
	GEQUAL(method->getParamCount(), 7);
	GEQUAL(method->getParamType(0), createMetaType<char>());
	GEQUAL(method->getParamType(1), createMetaType<int>());
	GEQUAL(method->getParamType(2), createMetaType<long long>());
	GEQUAL(method->getParamType(3), createMetaType<double>());
	GEQUAL(method->getParamType(4), createMetaType<string>());
	GEQUAL(method->getParamType(5), createMetaType<const char *>());
	GEQUAL(method->getParamType(6), createMetaType<CLASS_DATA>());

	METHOD(methodSum);
	GCHECK(method->isVariadic());
	GEQUAL(method->getParamCount(), 1);
	GEQUAL(method->getParamType(0), createMetaType<const GMetaVariadicParam *>());
}


GTEST(Lib_CheckParam)
{
	const GMetaClass * metaClass = getGlobalMetaClass();
	GCHECK(metaClass);
	
	const GMetaMethod * method;

	METHOD(methodGetInt);
	GCHECK(! method->checkParam(38, 0));
	GCHECK(! method->checkParam(38, 50));

	METHOD(methodAddInt);
	GCHECK(method->checkParam(38, 0));
	GCHECK(! method->checkParam("d", 0));
	GCHECK(! method->checkParam(38, 1));
	GCHECK(! method->checkParam(38, 130));

	METHOD(methodRefString);
	GCHECK(! method->checkParam(38, 0));
	GCHECK(! method->checkParam(38, 68));

	METHOD(methodConcatString);
	GCHECK(method->checkParam("abc", 0));
	GCHECK(method->checkParam(string("abc"), 0));
	GCHECK(! method->checkParam(3, 0));
	GCHECK(! method->checkParam(38, 1));
	GCHECK(! method->checkParam(38, 130));

	METHOD(methodAddData);
	GCHECK(method->checkParam(string("abc"), 0)); // even it passes, it will cause crash if we real do the invoke.
	GCHECK(method->checkParam((void *)0, 0)); // again, dangerous
	GCHECK(method->checkParam(CLASS_DATA(3), 0));
	GCHECK(! method->checkParam("abc", 0));
	GCHECK(! method->checkParam(38, 1));
	GCHECK(! method->checkParam(38, 130));

	METHOD(methodMakeData);
	GCHECK(method->checkParam(CLASS_DATA(3), 0));
	GCHECK(! method->checkParam("abc", 0));
	GCHECK(! method->checkParam(38, 1));

	METHOD(methodMakeDataByPointer);
	GCHECK(method->checkParam((CLASS_DATA *)0, 0));
	GCHECK(method->checkParam("abc", 0)); // dangerous
	GCHECK(! method->checkParam(CLASS_DATA(3), 0));
	GCHECK(! method->checkParam(38, 1));

	METHOD(methodManyParams);
	GCHECK(method->checkParam(98765321L, 0));
	GCHECK(method->checkParam(98765321L, 1));
	GCHECK(method->checkParam(98765321L, 2));
	GCHECK(method->checkParam(98765321L, 3));
	GCHECK(method->checkParam(98765321.5, 3));

	METHOD(methodSum);
	GCHECK(method->checkParam(38, 0));
	GCHECK(method->checkParam("abc", 1));
	GCHECK(method->checkParam(38, 10));
	GCHECK(method->checkParam(38, 100));
	GCHECK(method->checkParam(38, 1000));
}


GTEST(API_CheckParam)
{
	GMetaScopedPointer<IMetaService> service(createMetaService());
	GCHECK(service);

	GMetaScopedPointer<IMetaClass> metaClass(service->getGlobalMetaClass());
	GCHECK(metaClass);

	GMetaScopedPointer<IMetaMethod> method;

	METHOD(methodGetInt);
	GCHECK(! metaCheckParam(method, 38, 0));
	GCHECK(! metaCheckParam(method, 38, 50));

	METHOD(methodAddInt);
	GCHECK(metaCheckParam(method, 38, 0));
	GCHECK(! metaCheckParam(method, "d", 0));
	GCHECK(! metaCheckParam(method, 38, 1));
	GCHECK(! metaCheckParam(method, 38, 130));

	METHOD(methodRefString);
	GCHECK(! metaCheckParam(method, 38, 0));
	GCHECK(! metaCheckParam(method, 38, 68));

	METHOD(methodConcatString);
	GCHECK(metaCheckParam(method, "abc", 0));
	GCHECK(metaCheckParam(method, string("abc"), 0));
	GCHECK(! metaCheckParam(method, 3, 0));
	GCHECK(! metaCheckParam(method, 38, 1));
	GCHECK(! metaCheckParam(method, 38, 130));

	METHOD(methodAddData);
	GCHECK(metaCheckParam(method, string("abc"), 0)); // even it passes, it will cause crash if we real do the invoke.
	GCHECK(metaCheckParam(method, (void *)0, 0)); // again, dangerous
	GCHECK(metaCheckParam(method, CLASS_DATA(3), 0));
	GCHECK(! metaCheckParam(method, "abc", 0));
	GCHECK(! metaCheckParam(method, 38, 1));
	GCHECK(! metaCheckParam(method, 38, 130));

	METHOD(methodMakeData);
	GCHECK(metaCheckParam(method, CLASS_DATA(3), 0));
	GCHECK(! metaCheckParam(method, "abc", 0));
	GCHECK(! metaCheckParam(method, 38, 1));

	METHOD(methodMakeDataByPointer);
	GCHECK(metaCheckParam(method, (CLASS_DATA *)0, 0));
	GCHECK(metaCheckParam(method, "abc", 0)); // dangerous
	GCHECK(! metaCheckParam(method, CLASS_DATA(3), 0));
	GCHECK(! metaCheckParam(method, 38, 1));

	METHOD(methodManyParams);
	GCHECK(metaCheckParam(method, 98765321L, 0));
	GCHECK(metaCheckParam(method, 98765321L, 1));
	GCHECK(metaCheckParam(method, 98765321L, 2));
	GCHECK(metaCheckParam(method, 98765321L, 3));
	GCHECK(metaCheckParam(method, 98765321.5, 3));

	METHOD(methodSum);
	GCHECK(metaCheckParam(method, 38, 0));
	GCHECK(metaCheckParam(method, "abc", 1));
	GCHECK(metaCheckParam(method, 38, 10));
	GCHECK(metaCheckParam(method, 38, 100));
	GCHECK(metaCheckParam(method, 38, 1000));
}


GTEST(Lib_Invoke)
{
	const GMetaClass * metaClass = getGlobalMetaClass();
	GCHECK(metaClass);
	
	const GMetaMethod * method;


	CLASS * pobj = NULL;

	fieldMethodInt = 910;
	METHOD(methodGetInt);
	GEQUAL(fromVariant<int>(method->invoke(pobj)), 910);
	EXCEPT_META(method->invoke(pobj, 1));

	METHOD(methodAddInt);
	method->invoke(pobj, 2);
	GEQUAL(fieldMethodInt, 912);
	EXCEPT_META(method->invoke(pobj, 1, 5));

	fieldMethodString = "";
	METHOD(methodRefString);
	string & refString = fromVariant<string &>(method->invoke(pobj));
	GEQUAL(&fieldMethodString, &refString);
	refString = "reffff";
	GEQUAL(fieldMethodString, "reffff");
	EXCEPT_META(method->invoke(pobj, 1));

	fieldMethodString = "a";
	METHOD(methodConcatString);
	string s = fromVariant<string>(method->invoke(pobj, "bc"));
	GEQUAL(s, "abc");
	GEQUAL(fieldMethodString, "abc");
	EXCEPT_META(method->invoke(pobj, 1, 2));

	fieldMethodString = "bc";
	fieldMethodInt = 6;
	CLASS_DATA data("a", 5);
	METHOD(methodAddData);
	CLASS_DATA newData = fromVariant<CLASS_DATA>(method->invoke(pobj, data));
	GEQUAL(data.s, "a");
	GEQUAL(data.i, 5);
	GEQUAL(newData.s, "abc");
	GEQUAL(newData.i, 11);
	EXCEPT_META(method->invoke(pobj));

	fieldMethodString = "abc";
	fieldMethodInt = 6;
	data = CLASS_DATA("", 0);
	GDIFF(data.s, "abc");
	GDIFF(data.i, 6);
	METHOD(methodMakeData);
	method->invoke(pobj, data);
	GEQUAL(data.s, "abc");
	GEQUAL(data.i, 6);
	EXCEPT_META(method->invoke(pobj, 1, 2));

	fieldMethodString = "abc";
	fieldMethodInt = 6;
	data = CLASS_DATA("", 0);
	GDIFF(data.s, "abc");
	GDIFF(data.i, 6);
	METHOD(methodMakeDataByPointer);
	method->invoke(pobj, &data);
	GEQUAL(data.s, "abc");
	GEQUAL(data.i, 6);
	EXCEPT_META(method->invoke(pobj, 1, 2));

	METHOD(methodManyParams);
	method->invoke(pobj, 'A', 38, 9876532198765321LL, 1.99, "Many", "Too Many", CLASS_DATA("Data", 8));
	EXCEPT_META(method->invoke(pobj, 1));

	METHOD(methodSum);
	GEQUAL(fromVariant<int>(method->invoke(pobj)), (0));
	GEQUAL(fromVariant<int>(method->invoke(pobj, 1, 2, 3)), (1 + 2 + 3));
	GEQUAL(fromVariant<int>(method->invoke(pobj,
		18, 56, 102, 192, 3103, 39, 52, 691, 819, 130, 397, 19385
		)), (
		18 + 56 + 102 + 192 + 3103 + 39 + 52 + 691 + 819 + 130 + 397 + 19385
		));
}


GTEST(API_Invoke)
{
	GMetaScopedPointer<IMetaService> service(createMetaService());
	GCHECK(service);

	GMetaScopedPointer<IMetaClass> metaClass(service->getGlobalMetaClass());
	GCHECK(metaClass);

	GMetaScopedPointer<IMetaMethod> method;


	CLASS * pobj = NULL;

	fieldMethodInt = 910;
	METHOD(methodGetInt);
	GEQUAL(fromVariant<int>(metaCallMethod(method, pobj)), 910);
	EXCEPT_META(metaCallMethod(method, pobj, 1));

	METHOD(methodAddInt);
	metaCallMethod(method, pobj, 2);
	GEQUAL(fieldMethodInt, 912);
	EXCEPT_META(metaCallMethod(method, pobj));

	fieldMethodString = "";
	METHOD(methodRefString);
	string & refString = fromVariant<string &>(metaCallMethod(method, pobj));
	GEQUAL(&fieldMethodString, &refString);
	refString = "reffff";
	GEQUAL(fieldMethodString, "reffff");
	EXCEPT_META(metaCallMethod(method, pobj, 1));

	fieldMethodString = "a";
	METHOD(methodConcatString);
	string s = fromVariant<string>(metaCallMethod(method, pobj, "bc"));
	GEQUAL(s, "abc");
	GEQUAL(fieldMethodString, "abc");
	EXCEPT_META(metaCallMethod(method, pobj, 1, 2));

	fieldMethodString = "bc";
	fieldMethodInt = 6;
	CLASS_DATA data("a", 5);
	METHOD(methodAddData);
	CLASS_DATA newData = fromVariant<CLASS_DATA>(metaCallMethod(method, pobj, data));
	GEQUAL(data.s, "a");
	GEQUAL(data.i, 5);
	GEQUAL(newData.s, "abc");
	GEQUAL(newData.i, 11);
	EXCEPT_META(metaCallMethod(method, pobj, 1, 3));

	fieldMethodString = "abc";
	fieldMethodInt = 6;
	data = CLASS_DATA("", 0);
	GDIFF(data.s, "abc");
	GDIFF(data.i, 6);
	METHOD(methodMakeData);
	metaCallMethod(method, pobj, data);
	GEQUAL(data.s, "abc");
	GEQUAL(data.i, 6);
	EXCEPT_META(metaCallMethod(method, pobj));

	fieldMethodString = "abc";
	fieldMethodInt = 6;
	data = CLASS_DATA("", 0);
	GDIFF(data.s, "abc");
	GDIFF(data.i, 6);
	METHOD(methodMakeDataByPointer);
	metaCallMethod(method, pobj, &data);
	GEQUAL(data.s, "abc");
	GEQUAL(data.i, 6);
	EXCEPT_META(metaCallMethod(method, pobj, 1, 5));

	METHOD(methodManyParams);
	metaCallMethod(method, pobj, 'A', 38, 9876532198765321LL, 1.99, "Many", "Too Many", CLASS_DATA("Data", 8));
	EXCEPT_META(metaCallMethod(method, pobj, 1));

	METHOD(methodSum);
	GEQUAL(fromVariant<int>(metaCallMethod(method, pobj)), (0));
	GEQUAL(fromVariant<int>(metaCallMethod(method, pobj, 1, 2, 3)), (1 + 2 + 3));
	GEQUAL(fromVariant<int>(metaCallMethod(method, pobj,
		18, 56, 102, 192, 3103, 39, 52, 691, 819, 130, 397, 19385
		)), (
		18 + 56 + 102 + 192 + 3103 + 39 + 52 + 691 + 819 + 130 + 397 + 19385
		));
}


GTEST(Lib_Execute)
{
	const GMetaClass * metaClass = getGlobalMetaClass();
	GCHECK(metaClass);
	
	const GMetaMethod * method;


	CLASS * pobj = NULL;

	GVariant params[20];

	fieldMethodInt = 910;
	METHOD(methodGetInt);
	GEQUAL(fromVariant<int>(method->execute(pobj, params, 0)), 910);

	METHOD(methodAddInt);
	method->invoke(pobj, 2);
	GEQUAL(fieldMethodInt, 912);

	fieldMethodString = "";
	METHOD(methodRefString);
	string & refString = fromVariant<string &>(method->execute(pobj, params, 0));
	GEQUAL(&fieldMethodString, &refString);
	refString = "reffff";
	GEQUAL(fieldMethodString, "reffff");

	fieldMethodString = "a";
	METHOD(methodConcatString);
	params[0] = "bc";
	string s = fromVariant<string>(method->execute(pobj, params, 1));
	GEQUAL(s, "abc");
	GEQUAL(fieldMethodString, "abc");

	fieldMethodString = "bc";
	fieldMethodInt = 6;
	CLASS_DATA data("a", 5);
	METHOD(methodAddData);
	params[0] = data;
	CLASS_DATA newData = fromVariant<CLASS_DATA>(method->execute(pobj, params, 1));
	GEQUAL(data.s, "a");
	GEQUAL(data.i, 5);
	GEQUAL(newData.s, "abc");
	GEQUAL(newData.i, 11);

	fieldMethodString = "abc";
	fieldMethodInt = 6;
	data = CLASS_DATA("", 0);
	GDIFF(data.s, "abc");
	GDIFF(data.i, 6);
	METHOD(methodMakeData);
	params[0] = data;
	method->execute(pobj, params, 1);
	GEQUAL(data.s, "abc");
	GEQUAL(data.i, 6);

	fieldMethodString = "abc";
	fieldMethodInt = 6;
	data = CLASS_DATA("", 0);
	GDIFF(data.s, "abc");
	GDIFF(data.i, 6);
	METHOD(methodMakeDataByPointer);
	params[0] = &data;
	method->execute(pobj, params, 1);
	GEQUAL(data.s, "abc");
	GEQUAL(data.i, 6);

	METHOD(methodManyParams);
	params[0] = 'A'; params[1] = 38; params[2] = 9876532198765321LL;
	params[3] = 1.99; params[4] = "Many"; params[5] = "Too Many";
	data = CLASS_DATA("Data", 8);
	params[6] = data;
	method->execute(pobj, params, 7);

	METHOD(methodSum);
	GEQUAL(fromVariant<int>(method->execute(pobj, params, 0)), (0));
	params[0] = 1; params[1] = 2; params[2] = 3;
	GEQUAL(fromVariant<int>(method->execute(pobj, params, 3)), (1 + 2 + 3));
	params[0] = 18; params[1] = 56; params[2] = 102; params[3] = 192; params[4] = 3103;
	params[5] = 39; params[6] = 52; params[7] = 691, params[8] = 819; params[9] = 130;
	params[10] = 397; params[11] = 19385;
	GEQUAL(fromVariant<int>(method->execute(pobj, params, 12)), (
		18 + 56 + 102 + 192 + 3103 + 39 + 52 + 691 + 819 + 130 + 397 + 19385
		));
}


GTEST(Lib_PassParamByValueAndRef)
{
	const GMetaClass * metaClass = getGlobalMetaClass();
	GCHECK(metaClass);
	
	const GMetaMethod * method;


	CLASS * pobj = NULL;
	
	CLASS_DATA data("abc", 5);
	CLASS_DATA newData;

	fieldMethodInt = 2;
	fieldMethodString = "def";

	METHOD(methodAddData);
	newData = fromVariant<CLASS_DATA>(method->invoke(pobj, data));
	GEQUAL(data.i, 5); // data should not be changed because it was passed by value
	GDIFF(newData, data);
	GEQUAL(newData, methodAddData(data));

	fieldMethodInt = 2;
	fieldMethodString = "def";
	data.reset();

	GDIFF(data.i, fieldMethodInt);
	GDIFF(data.s, fieldMethodString);
	METHOD(methodMakeData);
	method->invoke(pobj, data);
	GEQUAL(data.i, fieldMethodInt);
	GEQUAL(data.s, fieldMethodString);
	EXCEPT_VARIANT(method->invoke(pobj, 1))

	fieldMethodInt = 2;
	fieldMethodString = "def";
	data.reset();

	GDIFF(data.i, fieldMethodInt);
	GDIFF(data.s, fieldMethodString);
	METHOD(methodMakeDataByPointer);
	method->invoke(pobj, &data);
	GEQUAL(data.i, fieldMethodInt);
	GEQUAL(data.s, fieldMethodString);
	EXCEPT_VARIANT(method->invoke(pobj, data))
}



} }

