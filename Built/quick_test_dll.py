import os

import sys

import ctypes


if sys.platform == 'win32':
	dll_path = os.path.abspath(
		os.path.normpath(
			os.path.join(
				os.curdir,
				'Win_mingw/libMoonCSFML.dll'
			)
		)
	)
else:
	dll_path = os.path.abspath(
		os.path.normpath(
			os.path.join(
				os.curdir,
				'Lin_gcc/libMoonCSFML.so'
			)
		)
	)
	os.environ['LD_LIBRARY_PATH'] = (
		os.environ['LD_LIBRARY_PATH']
		+ os.pathsep
		+ dll_path
	)
os.environ['PATH'] = os.environ['PATH'] + os.pathsep + dll_path


print('start!')

dll = ctypes.CDLL(dll_path)

print('library loaded!')

moon_Time = ctypes.c_ulonglong

dll.moon_Time_from_seconds.restype = moon_Time

dll.moon_Time_from_seconds.argtypes = [ctypes.c_float]

dll.moon_Time_as_seconds.restype = ctypes.c_float

dll.moon_Time_as_seconds.argtypes = [moon_Time]


tm = dll.moon_Time_from_seconds(13)

print(dll.moon_Time_as_seconds(tm))

print('end!')
