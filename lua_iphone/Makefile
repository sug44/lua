XBUILD=/Applications/Xcode.app/Contents/Developer/usr/bin/xcodebuild
PROJECT_ROOT=.
PROJECT=$(PROJECT_ROOT)/Lua_iPhone.xcodeproj
TARGET=Lua_iPhone

all: libLua51.a

Lua_iPhone:
	echo "Building Lua51 for iOS"

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

clean:
	-rm -f *.a *dll
