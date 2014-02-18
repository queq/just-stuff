module Zerocomp(Regin,Z);
	
	input [76:0]Regin;
	output reg Z;
		
always @(Regin) begin
	if(Regin==77'b0)
		Z=1'b1;
	else begin
		Z=1'b0;
	end
end
endmodule
