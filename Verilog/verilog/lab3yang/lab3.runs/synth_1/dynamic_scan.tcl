# 
# Synthesis run script generated by Vivado
# 

set_param xicom.use_bs_reader 1
debug::add_scope template.lib 1
set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7a100tcsg324-1

set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir C:/Users/dizzylay/vivado/lab3/lab3.cache/wt [current_project]
set_property parent.project_path C:/Users/dizzylay/vivado/lab3/lab3.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
read_verilog -library xil_defaultlib {
  C:/Users/dizzylay/vivado/lab3/lab3.srcs/sources_1/new/rom8x4.v
  C:/Users/dizzylay/vivado/lab3/lab3.srcs/sources_1/new/pattern.v
  C:/Users/dizzylay/vivado/lab3/lab3.srcs/sources_1/new/decoder3_8.v
  C:/Users/dizzylay/vivado/lab3/lab3.srcs/sources_1/new/divider.v
  C:/Users/dizzylay/vivado/lab3/lab3.srcs/sources_1/new/counter.v
  C:/Users/dizzylay/vivado/lab3/lab3.srcs/sources_1/new/dynamic_scan.v
}
read_xdc {{C:/Users/dizzylay/vivado/lab3/lab3.srcs/constrs_1/imports/实验2 -  简单组合电路设计_v3_2/Nexys4DDR_Master.xdc}}
set_property used_in_implementation false [get_files {{C:/Users/dizzylay/vivado/lab3/lab3.srcs/constrs_1/imports/实验2 -  简单组合电路设计_v3_2/Nexys4DDR_Master.xdc}}]

synth_design -top dynamic_scan -part xc7a100tcsg324-1
write_checkpoint -noxdef dynamic_scan.dcp
catch { report_utilization -file dynamic_scan_utilization_synth.rpt -pb dynamic_scan_utilization_synth.pb }
