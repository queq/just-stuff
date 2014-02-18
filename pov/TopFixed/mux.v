module mux(char, addEnhe, muxOut);
	parameter asciiEnhe=7'b0000010;
	//parameter asciiEnheMayusc=1000000;

	input [6:0] char;
	//input [6:0] asciiEnhe1;
	input addEnhe;	
	output reg [6:0] muxOut;
	

	always @(addEnhe or char)
		begin
			if(addEnhe) muxOut<=asciiEnhe;
			else muxOut<=char;
		end	
endmodule
