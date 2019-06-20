# 
# Synthesis run script generated by Vivado
# 

set_param xicom.use_bs_reader 1
debug::add_scope template.lib 1
set_msg_config -id {Common-41} -limit 4294967295
set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7a100tcsg324-1

set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir D:/lab1/lab1.cache/wt [current_project]
set_property parent.project_path D:/lab1/lab1.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
read_verilog -library xil_defaultlib C:/Users/wzc-1748995976/Desktop/3/lab3_1.v
read_xdc C:/Users/wzc-1748995976/Desktop/2/Nexys4DDR_Master.xdc
set_property used_in_implementation false [get_files C:/Users/wzc-1748995976/Desktop/2/Nexys4DDR_Master.xdc]

synth_design -top divider -part xc7a100tcsg324-1
write_checkpoint -noxdef divider.dcp
catch { report_utilization -file divider_utilization_synth.rpt -pb divider_utilization_synth.pb }
