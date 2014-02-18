`timescale 1ns / 1ps

module Convierte(
    input [3:0]Ver,
    output reg [6:0]Salida7seg
    );
		 
	always @(Ver)begin	
		case(Ver)
		//                        abc_defg
		7'b0000000: Salida7seg=7'b000_0001;//0
		7'b0000001: Salida7seg=7'b100_1111;//1
		7'b0000010: Salida7seg=7'b001_0010;//2
		7'b0000011: Salida7seg=7'b000_0110;//3
		7'b0000100: Salida7seg=7'b100_1100;//4
		7'b0000101: Salida7seg=7'b010_0100;//5
		7'b0000110: Salida7seg=7'b010_0000;//6
		7'b0000111: Salida7seg=7'b000_1111;//7
		7'b0001000: Salida7seg=7'b000_0000;//8
		7'b0001001: Salida7seg=7'b000_0100;//9
	
		7'b0001010: Salida7seg=7'b000_1000;//A
		7'b0001011: Salida7seg=7'b110_0000;//b
		7'b0001100: Salida7seg=7'b011_0001;//C
		7'b0001101: Salida7seg=7'b100_0010;//d
		7'b0001110: Salida7seg=7'b011_0000;//E
		7'b0001111: Salida7seg=7'b011_1000;//F

	/*
		8'h15: Salida7seg=7'b000_1100;//q
		8'h1D: Salida7seg=7'b100_0000;//w
		8'h24: Salida7seg=7'b011_0000;//E
		8'h2D: Salida7seg=7'b111_1010;//r
		8'h2C: Salida7seg=7'b111_0000;//t
		8'h35: Salida7seg=7'b100_0100;//Y
		8'h3C: Salida7seg=7'b110_0011;//u
		8'h43: Salida7seg=7'b100_1111;//i
		8'h44: Salida7seg=7'b110_0010;//O
		8'h4D: Salida7seg=7'b001_1000;//P
		8'h1C: Salida7seg=7'b000_1000;//A
		8'h1B: Salida7seg=7'b010_0100;//S
		8'h23: Salida7seg=7'b100_0010;//d
		8'h2B: Salida7seg=7'b011_1000;//F
		8'h34: Salida7seg=7'b010_0001;//G
		8'h33: Salida7seg=7'b110_1000;//h
		8'h3B: Salida7seg=7'b100_0011;//J
		8'h42: Salida7seg=7'b010_1000;//K
		8'h4B: Salida7seg=7'b111_0000;//L
		8'h4C: Salida7seg=7'b010_1010;//ñ
		8'h1A: Salida7seg=7'b001_0011;//Z
		8'h22: Salida7seg=7'b100_1000;//X
		8'h21: Salida7seg=7'b111_0010;//C
		8'h2A: Salida7seg=7'b100_0001;//V
		8'h32: Salida7seg=7'b110_0000;//b
		8'h31: Salida7seg=7'b110_1010;//n
		8'h3A: Salida7seg=7'b000_1001;//M
		*/
		default : Salida7seg=7'b000_0001;//0
		
		
		endcase
	end
endmodule
