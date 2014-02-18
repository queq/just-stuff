module shiftString(load, add, clk, muxOut, delete, string);

	input  load, add, clk, delete;
	input [6:0] muxOut;
	output reg [76:0] string;
	reg [76:0] temp;
	
always @(posedge clk) begin
 
		if(load==1) temp<=77'b01000000100000010000001000000100000010000001000000100000010000001000000100000;

		else if (add==1) temp<={string[69:0],muxOut[6:0]};
		else if (delete==1) temp<={7'b0100000,string[76:7]};
		else temp<=temp;
		end 	

	always @(temp) string<=temp;

endmodule
