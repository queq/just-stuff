`timescale 1ns / 1ps
module top_leds(
input clk,
input [76:0] string,
input new_string,
output [15:0] ledsOut
);

wire leer_ram;
wire [15:0]dato_ram;
wire[7:0] dir;
wire run_efect;
wire [6:0]efect;
wire efect0;
wire efect1;
wire efect2;
wire efect3;
wire efect4;
wire efect5;
//wire efect6;
//falta control
 select_efect seled(.efect(efect),.efect0(efect0),.efect1(efect1),.efect2(efect2),.efect3(efect3),.efect4(efect4),.efect5(efect5)/*,.efect6(efect6)*/);
top_RAM  trm(.clk(clk), .load(efect3),.efect0(efect0), .ledsOut(ledsOut),.dato_ram(dato_ram),.dir(dir),.run_efect(run_efect));
top_ASCCI TASCC(.clk(clk),.string(string),.new_string(new_string),.datoram(dato_ram),.dir(dir),.run_efect(run_efect),.efect(efect));
top_efect2 ef2(.efect2(efect2));
top_efect1 ef1(.efect1(efect1));
top_efect4 ef4(.efect4(efect4));
top_efect5 ef5(.efect5(efect5));


	
endmodule
