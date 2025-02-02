CC = "C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.42.34433/bin/Hostx64/x64/cl.exe"

CFLAGS = /EHsc /std:c++17 /I"C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.42.34433/include" \
         /I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/ucrt"

LIB_PATHS = "C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.42.34433/lib/x64" \
            "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22000.0/um/x64" \
            "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22000.0/ucrt/x64"

TARGET = mergesort.exe

SRC = mergesort.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) /Fe:$(TARGET) /link /LIBPATH:"C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.42.34433/lib/x64" \
	/LIBPATH:"C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22000.0/um/x64" \
	/LIBPATH:"C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22000.0/ucrt/x64"

clean:
	del /Q $(TARGET)
