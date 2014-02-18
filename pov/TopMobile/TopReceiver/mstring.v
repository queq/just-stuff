module mstring (WriteString, char, String, reset, clk_2);
   input WriteString;
   input [6:0] char;
   input       reset;
   input       clk_2;
   
   output reg [0:76] String;

  always @ (posedge clk_2 or posedge reset) begin
     if(reset==1'b1) begin
	  String<=77'b0;
	end
     else begin
	if (WriteString == 1'b1) begin	
	   String <= {String[7:76], char};
	end
     end
  end
   
endmodule 
