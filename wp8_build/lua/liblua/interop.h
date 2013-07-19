#pragma once

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <lnet.h>

#include <string>

using namespace Platform;

namespace LuaCX
{	
	public ref class Interop sealed
	{
	public:
		// Lua API
		typedef String^      string;

	private:
		Interop();

		inline static lua_State * TS (IntPtr  ptr) {return (lua_State*)(void*) ptr;}
		inline static IntPtr TC(const char * ptr) { return IntPtr ((void*) ptr); }
		inline static std::string TC (string str) 
		{
			return std::string (str->Begin (), str->End ());
		}

	public:


		static int LuaGC(IntPtr state, int what, int data)
		{
			return ::lua_gc (TS(state), what, data);
		}

		static IntPtr LuaTypeName (IntPtr luaState, int type)
		{
			return TC(::lua_typename (TS(luaState), type));
		}

		static void LuaLError(IntPtr luaState, string message)
		{
			::luaL_error (TS(luaState), TC (message).c_str ());
		}

		static void LuaLWhere(IntPtr luaState, int level)
		{
			::luaL_where(TS(luaState), level);
		}

		static IntPtr LuaLNewState ()
		{
			return ::luaL_newstate ();
		}

		static void LuaClose(IntPtr luaState)
		{
			::lua_close (TS(luaState));
		}

		static void LuaLOpenLibs(IntPtr luaState)
		{
			::luaL_openlibs(TS(luaState));
		}

		static int LuaLLoadString(IntPtr luaState, string chunk)
		{
			return ::luaL_loadstring(TS(luaState), TC(chunk).c_str());
		}

		static int LuaLLoadStringArray(IntPtr luaState,const Platform::Array<uint8>^ chunk)
		{
			const char * data = (char *)chunk->begin();
			return ::luaL_loadstring(TS(luaState), data);
		}

		static void LuaCreateTable(IntPtr luaState, int narr, int nrec)
		{
			::lua_createtable(TS(luaState), narr, nrec);
		}

		static void LuaGetTable(IntPtr luaState, int index)
		{
			::lua_gettable(TS(luaState), index);
		}

		static void LuaSetTop(IntPtr luaState, int newTop)
		{
			::lua_settop (TS(luaState), newTop);
		}

		static void LuaInsert(IntPtr luaState, int newTop)
		{
			::lua_insert(TS(luaState), newTop);
		}

		static void LuaRemove(IntPtr luaState, int index)
		{
			::lua_remove(TS(luaState), index);
		}

		static void LuaRawGet(IntPtr luaState, int index)
		{
			::lua_rawget(TS(luaState), index);
		}

		static void LuaSetTable(IntPtr luaState, int index)
		{
			::lua_settable(TS(luaState), index);
		}

		static void LuaRawSet(IntPtr luaState, int index)
		{
			::lua_rawset(TS(luaState), index);
		}


		static void LuaSetMetatable(IntPtr luaState, int objIndex)
		{
			::lua_setmetatable(TS(luaState), objIndex);
		}


		static int LuaGetMetatable(IntPtr luaState, int objIndex)
		{
			return ::lua_getmetatable(TS(luaState), objIndex);
		}


		static int LuaNetEqual(IntPtr luaState, int index1, int index2)
		{
			return ::luanet_equal(TS(luaState), index1, index2);
		}


		static void LuaPushValue(IntPtr luaState, int index)
		{
			::lua_pushvalue(TS(luaState), index);
		}


		static void LuaReplace(IntPtr luaState, int index)
		{
			::lua_replace(TS(luaState), index);
		}


		static int LuaGetTop(IntPtr luaState)
		{
			return ::lua_gettop(TS(luaState));
		}


		static int LuaType(IntPtr luaState, int index)
		{
			return ::lua_type(TS(luaState), index);
		}


		static int LuaLRef(IntPtr luaState, int registryIndex)
		{
			return ::luaL_ref(TS(luaState), registryIndex);
		}


		static void LuaRawGetI(IntPtr luaState, int tableIndex, int index)
		{
			::lua_rawgeti(TS(luaState), tableIndex, index);
		}

		static void LuaRawSetI(IntPtr luaState, int tableIndex, int index)
		{
			::lua_rawseti(TS(luaState), tableIndex, index);
		}


		static IntPtr LuaNewUserData(IntPtr luaState, unsigned int size)
		{
			return ::lua_newuserdata(TS(luaState), size);
		}

		static IntPtr LuaToUserData(IntPtr luaState, int index)
		{
			return ::lua_touserdata(TS(luaState), index);
		}


		static void LuaLUnref(IntPtr luaState, int registryIndex, int reference)
		{
			::luaL_unref(TS(luaState), registryIndex, reference);
		}


		static int LuaIsString(IntPtr luaState, int index)
		{
			return ::lua_isstring(TS(luaState), index);
		}


		static int LuaIsCFunction(IntPtr luaState, int index)
		{
			return ::lua_iscfunction(TS(luaState), index);
		}


		static void LuaPushNil(IntPtr luaState)
		{
			::lua_pushnil(TS(luaState));
		}


		static int LuaCall(IntPtr luaState, int nArgs, int nResults)
		{
			::lua_call(TS(luaState), nArgs, nResults);
			return 0;
		}


		static int LuaNetPCall(IntPtr luaState, int nArgs, int nResults, int errfunc)
		{
			return ::luanet_pcall(TS(luaState), nArgs, nResults, errfunc);
		}


		static IntPtr LuaToCFunction(IntPtr luaState, int index)
		{
			return ::lua_tocfunction(TS(luaState), index);
		}


		static double LuaNetToNumber(IntPtr luaState, int index)
		{
			return ::luanet_tonumber(TS(luaState), index);
		}

		static int LuaToBoolean(IntPtr luaState, int index)
		{
			return ::lua_toboolean(TS(luaState), index);
		}

		static IntPtr LuaToLString(IntPtr luaState, int index, size_t * strLen)
		{
			return TC(::lua_tolstring(TS(luaState), index, strLen));
		}

		static void LuaAtPanic(IntPtr luaState, IntPtr panicf)
		{
			::lua_atpanic(TS(luaState), (lua_CFunction) (void*)panicf);
		}

		static void LuaPushStdCallCFunction(IntPtr luaState, IntPtr function)
		{
			::lua_pushstdcallcfunction(TS(luaState), (lua_stdcallCFunction) (void*) function);
		}

		static void LuaPushNumber(IntPtr luaState, double number)
		{
			::lua_pushnumber(TS(luaState), number);
		}

		static void LuaPushBoolean(IntPtr luaState, int value)
		{
			::lua_pushboolean(TS(luaState), value);
		}

		static void LuaNetPushLString(IntPtr luaState, string str, size_t size)
		{
			::luanet_pushlstring(TS(luaState), TC(str).c_str(), size);
		}

		static void LuaPushString(IntPtr luaState, string str)
		{
			::lua_pushstring(TS(luaState), TC(str).c_str());
		}

		static int LuaLNewMetatable(IntPtr luaState, string meta)
		{
			return ::luaL_newmetatable(TS(luaState), TC(meta).c_str ());
		}

		static void LuaGetField(IntPtr luaState, int stackPos, string meta)
		{
			::lua_getfield(TS(luaState), stackPos, TC(meta).c_str());
		}

		static IntPtr LuaLCheckUData(IntPtr luaState, int stackPos, string meta)
		{
			return ::luaL_checkudata(TS(luaState), stackPos, TC(meta).c_str ());
		}

		static int LuaLGetMetafield(IntPtr luaState, int stackPos, string field)
		{
			return ::luaL_getmetafield(TS(luaState), stackPos, TC(field).c_str());
		}

		static int LuaNetLoadBuffer(IntPtr luaState, string buff, size_t size, string name)
		{
			return ::luanet_loadbuffer(TS(luaState), TC(buff).c_str(), size, TC(name).c_str());
		}

		static int LuaNetLoadBufferArray(IntPtr luaState, const Array<uint8>^ buff, size_t size, string name)
		{
			return ::luanet_loadbuffer(TS(luaState), (char *)buff->begin (), size, TC(name).c_str());
		}

		static int LuaNetLoadFile(IntPtr luaState, string filename)
		{
			return ::luanet_loadfile(TS(luaState), TC(filename).c_str());
		}

		static void LuaError(IntPtr luaState)
		{
			::lua_error(TS(luaState));
		}

		static int LuaCheckStack(IntPtr luaState, int extra)
		{
			return ::lua_checkstack(TS(luaState), extra);
		}

		static  int LuaNext (IntPtr luaState, int index)
		{
			return ::lua_next(TS(luaState), index);
		}

		static void LuaPushLightUserData(IntPtr luaState, IntPtr udata)
		{
			::lua_pushlightuserdata(TS(luaState), (void *)udata);
		}

		static int LuaLCheckMetatable(IntPtr luaState, int obj)
		{
			return ::luaL_checkmetatable(TS(luaState), obj);
		}

		static int LuaGetHookMask(IntPtr luaState)
		{
			return ::lua_gethookmask(TS(luaState));
		}

		static int LuaSetHook(IntPtr luaState, IntPtr func, int mask, int count)
		{
			return ::lua_sethook(TS(luaState), (lua_Hook)(void *)func, mask, count);
		}

		static int LuaGetHookCount(IntPtr luaState)
		{
			return ::lua_gethookcount(TS(luaState));
		}

		static IntPtr LuaGetLocal(IntPtr luaState, IntPtr ar, int n)
		{
			return TC(::lua_getlocal(TS(luaState), (lua_Debug *)(void *)ar, n));
		}

		static IntPtr LuaSetLocal(IntPtr luaState, IntPtr ar, int n)
		{
			return TC(::lua_setlocal(TS(luaState), (lua_Debug*)(void *) ar, n));
		}

		static IntPtr LuaGetUpValue(IntPtr luaState, int funcindex, int n)
		{
			return TC(::lua_getupvalue(TS(luaState), funcindex, n));
		}

		static IntPtr LuaSetUpValue(IntPtr luaState, int funcindex, int n)
		{
			return TC(::lua_setupvalue(TS(luaState), funcindex, n));
		}

		static int LuaNetToNetObject(IntPtr luaState, int index)
		{
			return ::luanet_tonetobject(TS(luaState), index);
		}

		static void LuaNetNewUData(IntPtr luaState, int val)
		{
			::luanet_newudata(TS(luaState), val);
		}

		static int LuaNetRawNetObj(IntPtr luaState, int obj)
		{
			return ::luanet_rawnetobj(TS(luaState), obj);
		}

		static int LuaNetCheckUData(IntPtr luaState, int ud, string tname)
		{
			return ::luanet_checkudata(TS(luaState), ud, TC(tname).c_str());
		}

		static IntPtr LuaNetGetTag()
		{
			return ::luanet_gettag();
		}

		static void LuaNetPushGlobalTable(IntPtr luaState)
		{
			::luanet_pushglobaltable(TS(luaState));
		}

		static void LuaNetPopGlobalTable(IntPtr luaState)
		{
			::luanet_popglobaltable(TS(luaState));
		}

		static void LuaNetGetGlobal(IntPtr luaState, string name)
		{
			::luanet_getglobal(TS(luaState), TC(name).c_str());
		}

		static void LuaNetSetGlobal(IntPtr luaState, string name)
		{
			::luanet_setglobal(TS(luaState), TC(name).c_str());
		}																							

		static int LuaNetRegistryIndex()
		{
			return ::luanet_registryindex();
		}

	};
}