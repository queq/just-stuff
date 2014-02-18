`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:51:19 05/25/2013 
// Design Name: 
// Module Name:    Divisor1k 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Divisor1k(
	input Reloj,
	output reg Frec=0 
);

reg[14:0] cont=0;

	always@(posedge Reloj)	begin
		if(cont==25'b110000110101000)begin
			cont<=0;
			Frec<=~Frec;
		end
		else cont<=cont+1;
	end
endmodule
