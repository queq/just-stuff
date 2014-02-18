module counter(delete, clk, add, load, counter);

	input delete, add, load;
	input clk;
	output reg [3:0] counter;	
	reg [3:0] temp;
	
	initial begin
		temp = 4'b0000;
	end
    
	always @(posedge clk) begin
		if (load) temp=4'b0000;
		else if(delete==1 & temp==4'b0000) temp=temp;
			else if (delete==1) temp=temp-1'b1;
		     		else if(add==1) temp=temp+1'b1;
			  		else temp=temp;
	end 

	always @(temp) begin
	counter<=temp;
	end

endmodule
