module test (String, CharSalida, clk, ready, reset);
   
   input [0:76] String;
   input 	clk;
   input 	ready;
   input 	reset;
   
   output reg [0:6] CharSalida;
   
   reg [0:76] 	    ST;
   reg 		    band;
   reg [3:0] 	    count;
   reg [25:0] 	    counter;
   
   parameter period=25000000;
   
   always @(posedge clk or posedge reset) begin
      
      if (reset==1)begin
	 counter=0;
	 band=0;
	 CharSalida<=7'b1111111;
	 ST<=77'b0;
      end
      
      else begin
	 if (ready==1'b1 && band==0) begin
	    count<=0;
	    ST<=77'b0;
	 end
	 if (ready==0) begin
	    band=0;
	 end
	 
	 case (count)
	   4'b1011:begin
	   end
	   
	   default:begin
	      if (count == 0)
		ST<=String;
	      
	      if (ST!=77'b0) begin
		 if (counter == period-1) begin
		    counter = 0;
		    CharSalida <= ST[0:6];
		    ST<={ST[7:76], 7'b0000000};
		    count <= count +1;
		    band=1'b1;
		 end
		 else counter = counter +1'b1;
	      end
	   end // case: default
	 endcase
      end
   end
endmodule 
