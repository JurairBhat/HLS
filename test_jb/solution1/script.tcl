############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project test_jb
set_top fft
add_files fft.cpp
add_files -tb fft_test.cpp
open_solution "solution1"
set_part {xc7a200tfbg676-2}
create_clock -period 10 -name default
#source "./test_jb/solution1/directives.tcl"
csim_design -clean -O -setup
csynth_design
cosim_design
export_design -format ip_catalog
