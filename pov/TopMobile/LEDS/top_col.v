`timescale 1ns / 1ps
module comp_col(   //comparador de contador de columnas de cada caracter
    input [3:0] col,
    output reg top_col
    );
	 
always @(col) begin
		if (col==4'b1111) top_col <= 1'b1;
		else top_col <= 1'b0;
	end


endmodule
