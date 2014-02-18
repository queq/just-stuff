`timescale 1ns / 1ps

module Selector_Display(
    input [6:0]Char,
	 input [1:0]Sel_Anodos,
	 output reg [3:0]Ver
    );
	 	
	 always@(*)begin
		case(Sel_Anodos)
			2'b00: Ver<=4'b0000;
			2'b01: Ver<=4'b0000;
			2'b10: Ver<=Char[3:0];
			2'b11: Ver<=Char[6:4];
		endcase
	end

endmodule
