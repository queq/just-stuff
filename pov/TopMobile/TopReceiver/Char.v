module Char (clk_2, rxd, WriteChar, error,  char, reset);
   input clk_2;
   input rxd;
   input WriteChar;
   input error;
   input reset;
 
   output reg [6:0] char;
 
   
   always @ (posedge clk_2 or posedge reset) begin 
      if(reset==1'b1) begin
	 char<=7'b0000000;
	end
      else begin
	 if (error == 1'b1) 
	   char<=7'b0000010;
	 
	 if (WriteChar == 1'b1) begin
	    char<={rxd, char[6:1]};
	 end
      end // else: !if(reset==1'b1)
   end // always @ (posedge clk_2)
   
endmodule 
