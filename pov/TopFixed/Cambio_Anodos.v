`timescale 1ns / 1ps


module Cambio_Anodos(
	input Reloj,
	output reg [1:0]Sel_Anodos=0
    );

always @(posedge Reloj)
	Sel_Anodos<=Sel_Anodos+1;
endmodule
