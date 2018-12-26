.PHONY: all

all: ios watchos tvos

ios: ./ios/liblua53.framework/liblua53
./ios/liblua53.framework/liblua53:
	xcodebuild  -project lua.ios.xcodeproj -configuration Release -sdk iphonesimulator
	xcodebuild  -project lua.ios.xcodeproj  -configuration Release -sdk iphoneos
	ditto ./Build/Release-iphoneos/ ./ios/
	rm ./ios/liblua53.framework/liblua53
	lipo -create ./build/Release-iphonesimulator/liblua53.framework/liblua53  ./build/Release-iphoneos/liblua53.framework/liblua53 -output  ./ios/liblua53.framework/liblua53
	/usr/libexec/PlistBuddy -c "Add :CFBundleSupportedPlatforms: string iPhoneSimulator" ./ios/liblua53.framework/Info.plist

watchos: ./watchos/liblua53.framework/liblua53
./watchos/liblua53.framework/liblua53:
	xcodebuild  -project lua.watchos.xcodeproj -configuration Release -sdk watchsimulator
	xcodebuild  -project lua.watchos.xcodeproj  -configuration Release -sdk watchos
	ditto ./Build/Release-watchos/ ./watchos/
	rm ./watchos/liblua53.framework/liblua53
	lipo -create ./build/Release-watchsimulator/liblua53.framework/liblua53  ./build/Release-watchos/liblua53.framework/liblua53 -output  ./watchos/liblua53.framework/liblua53
	/usr/libexec/PlistBuddy -c "Add :CFBundleSupportedPlatforms: string WatchSimulator" ./watchos/liblua53.framework/Info.plist

tvos: ./tvos/liblua53.framework/liblua53
./tvos/liblua53.framework/liblua53:
	xcodebuild  -project lua.tvos.xcodeproj -configuration Release -sdk appletvsimulator
	xcodebuild  -project lua.tvos.xcodeproj  -configuration Release -sdk appletvos
	ditto ./Build/Release-appletvos/ ./tvos/
	rm ./tvos/liblua53.framework/liblua53
	lipo -create ./build/Release-appletvsimulator/liblua53.framework/liblua53  ./build/Release-appletvos/liblua53.framework/liblua53 -output  ./tvos/liblua53.framework/liblua53
	/usr/libexec/PlistBuddy -c "Add :CFBundleSupportedPlatforms: string AppleTVSimulator" ./tvos/liblua53.framework/Info.plist

clean:
	rm -Rf build
	rm -Rf ./ios/
	rm -Rf ./watchos/
	rm -Rf ./tvos/