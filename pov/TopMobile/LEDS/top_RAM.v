`timescale 1ns / 1ps
module top_RAM( clk, load, efect0, ledsOut,dato_ram,dir,run_efect);
	input clk;
	input load; //Efect3
	input [15:0] dato_ram;
	input run_efect;
	input efect0; //Efecto fijo

	//input [7:0] d;
	//input esc;
	output [15:0] ledsOut;
	output [7:0] dir;


	//wire [15:0] C;

	wire rst;
	wire add1;
	wire reset1;
	wire add2;
	wire reset2;
	wire top1;
	wire top2;
	wire clk_out;
	wire new_col;
	wire reset_new;
	wire load_crt;
	wire done_crt;
	wire load_leds;
	wire [2:0] vuelta;
	wire [3:0] T;
	
	impresion imp( .clk(clk),.load_leds(load_leds),.leds(dato_ram),.ledsOut(ledsOut),.T(T));
	recorrido_col recol(.clk_out(clk_out),.load_crt(load_crt), .done_crt(done_crt), .dir(dir), .new_col(new_col), .reset_new(reset_new));
	divisor_de_frecuecia div_fr(.rst(rst),.clk(clk),.clk_out(clk_out));
	acc_1 acca (.vuelta(vuelta), .clk(clk), .add_1(add1),.reset_1(reset1));
	acc_2 accb (.T(T), .clk(clk), .add_2(add2), .reset_2(reset2));
	comp_1  coma (.vuelta(vuelta), .top_1(top1));
	comp_2  comb (.T(T), .top_2(top2));
	control_leer contr(.clk(clk),.load_e(load),.efect0(efect0),.add_1(add1),.add_2(add2),.reset_1(reset1),.reset_2(reset2),.top_1(top1),.top_2(top2),.load_crt(load_crt),.done_crt(done_crt),.new_col(new_col),.reset_new(reset_new),.load_led(load_leds),.rst(rst),.run_efect(run_efect)); 
	
	//	top_efect toef(.clk(clk),.load(loa),.leds(A),.ledsOut(B),.dir(dr),.leer(loadm), .Efect(efect));	
		endmodule

