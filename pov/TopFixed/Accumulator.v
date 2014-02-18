module Accumulator (MsbR, Shift, clk, D, rst);
	input MsbR;
	input Shift;
	input clk;
	input rst;
	output reg [6:0] D;
	reg [6:0] temp;



always @(negedge clk) begin
	if(rst) begin
		temp<=7'b0000000;
	end
	else begin
		if(Shift)
			temp<={temp[5:0],MsbR};
		else
			temp<=temp;
	end
end

always @(temp)begin
	D<=temp;
end
endmodule

