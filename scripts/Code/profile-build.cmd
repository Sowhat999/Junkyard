@echo off

pushd %~dp0..\..\projects\Windows

vcperf /start Junkyard
msbuild Junkyard.sln -property:Configuration=Debug /t:Rebuild
vcperf /stop Junkyard Junkyard.etl

popd