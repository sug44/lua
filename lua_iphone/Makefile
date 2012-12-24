XBUILD=/Applications/Xcode.app/Contents/Developer/usr/bin/xcodebuild
PROJECT_ROOT=.
PROJECT=$(PROJECT_ROOT)/Lua_iPhone.xcodeproj
TARGET=Lua_iPhone

all: libLua51.a

libLua51-i386.a: Lua_iPhone
	$(XBUILD) -project $(PROJECT) -target $(TARGET) -sdk iphonesimulator -configuration Release clean build
	-mv $(PROJECT_ROOT)/build/Release-iphonesimulator/libLua_iPhone.a $@

libLua51-armv7.a: Lua_iPhone
	$(XBUILD) -project $(PROJECT) -target $(TARGET) -sdk iphoneos -arch armv7 -configuration Release clean build
	-mv $(PROJECT_ROOT)/build/Release-iphoneos/libLua_iPhone.a $@

libLua51-armv7s.a: Lua_iPhone
	$(XBUILD) -project $(PROJECT) -target $(TARGET) -sdk iphoneos -arch armv7s -configuration Release clean build
	-mv $(PROJECT_ROOT)/build/Release-iphoneos/libLua_iPhone.a $@

libLua51.a: libLua51-i386.a libLua51-armv7.a libLua51-armv7s.a
	lipo -create -output $@ $^

#Lua51.dll: facebook.cs enum.cs Makefile extensions.cs AssemblyInfo.cs libFacebookSDK.a
#	/Developer/MonoTouch/usr/bin/btouch -e facebook.cs AssemblyInfo.cs -s=enum.cs -x=extensions.cs --out=$@ --link-with=libFacebookSDK.a,libFacebookSDK.a

clean:
	-rm -f *.a *dll
