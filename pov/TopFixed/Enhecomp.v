module Enhecomp(D, enhe);

	input [0:6]D;
	output reg enhe;

always @(D) begin
	if(D==7'b0000001 || D==7'b0000010)
		enhe=1'b1;
	else begin
		enhe=1'b0;
	end
end
endmodule
