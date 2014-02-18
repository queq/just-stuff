`timescale 1ns / 1ps
module top_ASCCI(
input clk,
input [76:0] string,
input new_string,
input [7:0]dir,
output [15:0]datoram,
output [6:0] efect,
output run_efect
 //abilita y desa el bus de direcion de ram de cada modulo
);

wire [3:0]col;
wire top_col;
wire [3:0]n_ascci;
wire top_ascci;
wire add_ascci;
wire reset_ascci;
wire add_col;
wire reset_col;
wire add_dirram;
wire reset_dirram;
wire leer_rom;
wire leer_ram;
wire [6:0]ascci;
wire [10:0]dir_rom;
wire wram;
wire [15:0]datorom;
wire [10:0]dir_in;
wire [7:0] d_ram;
wire [7:0] dir_ram;
wire done;


select_dir seldir(.clk(clk),.d_ram(d_ram),.dir_ram(dir_ram),.dir(dir),.leer_ram(leer_ram) );
comp_col comcol(.col(col),.top_col(top_col));
compn_ascci camasc (.n_ascci(n_ascci),.top_ascci(top_ascci));
cont_ascci aonasc (.n_ascci(n_ascci),.clk(clk),.add_ascci(add_ascci),.reset_ascci(reset_ascci));
cont_col aoncol(.clk(clk),.add_col(add_col),.reset_col(reset_col),.col(col));
cont_ram conra (.clk(clk),.add_dirram(add_dirram),.reset_dirram(reset_dirram),.dir_ram(dir_ram));
control_ascci contrascc (.clk(clk),.top_ascci(top_ascci),.top_col(top_col),.add_dirram(add_dirram),.reset_dirram(reset_dirram),.add_col(add_col),.reset_col(reset_col),.add_ascci(add_ascci),.reset_ascci(reset_ascci),.leer_rom(leer_rom),.leer_ram(leer_ram),.new_string(new_string),.init(init),.done(done),.run_efect(run_efect));
dir_ascci dirasc (.dir_in(dir_in),.clk(clk),.dir_rom(dir_rom),.col(col),.done(done));
m_plexor mplex(.string(string),.n_ascci(n_ascci),.ascci(ascci),.efect(efect) );
ram ra (.clk(clk),.direccionram(d_ram),.wram(leer_ram),.datorom(datorom),.datoram(datoram));
rom ro (.clk(clk),.leer_rom(leer_rom),.dir_rom(dir_rom),.dato_rom(datorom));
top_multiplicador mult(.clk(clk),.init(init),.A(ascci),.pp(dir_in), .done(done));
	

endmodule
