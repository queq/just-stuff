module SevenCont(Start, rst, clk, outcont);

	input Start;
	input rst;
	input clk; 
	output reg outcont;
	reg [3:0] tempcont;
	reg temp_out;

initial begin
	outcont=1'b0;
end

always @(negedge clk) begin
	if(rst) begin
		tempcont = 4'b0000;
		temp_out=0;
	end
	else begin
		if(tempcont == 4'b1110)begin
			temp_out = 1;
			tempcont = tempcont+1;
		end
		else begin 
			if(Start) begin
		  	tempcont = 4'b0000;
				temp_out=0;
			end
		  else begin
				if(tempcont == 4'b1111) begin
					tempcont=tempcont;
					temp_out=0;
				end
				else begin
		  		tempcont = tempcont+1;
					temp_out=0;
				end			
			end		
		end
	end
end

always @(temp_out) begin
	outcont=temp_out;
end
endmodule



