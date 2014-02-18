module counter (clk_2, char_count, str_count, reset, WriteChar, WriteString);
//-------------Input Ports-----------------------------
   input clk_2 ;
   input reset;
   input WriteString;
   input WriteChar;
//-------------Output Ports----------------------------
   output reg [3:0] char_count;
   output reg [3:0] str_count;
//------------Code Starts Here-------------------------
   
always @ (posedge clk_2 or posedge reset) begin : COUNTER// Block Name
   
   if (reset == 1'b1) begin
      char_count <= 4'b1000;
      str_count <= 4'b1011;
   end
   
   else begin
     if (WriteChar == 1'b0)
    	 char_count <= 4'b1000;
      else
   	 char_count <= char_count - 1'b1;
      
      if (WriteString == 1'b1) begin
	 if (str_count == 4'b0000)
	   str_count <= 4'b1011;
	 else
	   str_count <= str_count - 1'b1; 
      end
   end // else: !if(reset == 1'b1)
end // fin del bloque COUNTER

endmodule // counter
