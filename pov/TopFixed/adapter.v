module adapter ( change, complete, clk, changeOut, completeOut ) ;

	input change, complete;
	input clk;
	output reg changeOut, completeOut;
	reg changeOuttemp, completeOuttemp;
	
	always @(change or complete) begin 
		changeOuttemp<=change;
		completeOuttemp<=complete;
	end 
	

	always @(posedge clk) begin 
		changeOut<=changeOuttemp;
		completeOut<=completeOuttemp;
	end


endmodule
