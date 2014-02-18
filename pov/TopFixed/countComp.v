module countComp(counter,cCounter);
	input [3:0] counter;
	output reg cCounter;	
	
	always @(counter) begin
		if (counter>=4'b1010) cCounter=1;
		else cCounter=0;
	end	

endmodule
