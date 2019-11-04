project('HandmadeHero', 'c','cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++17'])

cc = meson.get_compiler('c')
cxx = meson.get_compiler('cpp')

user32_lib = cxx.find_library('user32')

exe = executable('handmade', 
  'code/handmain.cpp',
  dependencies : [user32_lib],
  gui_app : true)


test('basic', exe)

