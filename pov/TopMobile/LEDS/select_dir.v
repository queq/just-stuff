`timescale 1ns / 1ps
module select_dir(
	input clk,
    output reg[7:0] d_ram, //direccion final ram leer o guardar
    input [7:0] dir_ram, //direcc ram de ascci escribir
    input [7:0] dir,	//direccion de recorrido col leer
    input leer_ram
     /*output efect6,*/
    );
					
always @(leer_ram,d_ram,dir,dir_ram) begin

		if(leer_ram==1'b1) d_ram<=dir; //para imprimir 
		else d_ram<=dir_ram ; //para guardar
		
		end
endmodule

