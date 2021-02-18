############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project FFT
set_top fft
add_files fft.cpp
add_files -tb fft_test.cpp -cflags "-DHW_COSIM"
open_solution "solution1"
set_part {xc7a35t-cpg236-1}
create_clock -period 10 -name default
#source "./FFT/solution1/directives.tcl"
csim_design -clean -setup
csynth_design
cosim_design
export_design -format ip_catalog
