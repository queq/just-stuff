module top_multiplicador(clk, init, A, pp, done);
	input clk;
	input init;
	input [6:0] A;
	output [10:0] pp;
	output done;
	wire [10:0] w_A;
	wire [4:0] w_B;
	wire w_acc;
	wire w_ld_rst;
	wire w_Z; 
	wire w_lsb_B;
	wire w_shift; 

	acumulador acumulador1 (.in_A(w_A), .clk(clk), .acc(w_acc), .reset(w_ld_rst), .pp(pp));
	comp comp1 (.in_comp(w_B), .Z(w_Z));
	lslA lslA1 (.in_A(A), .clk(clk), .load(w_ld_rst), .shift(w_shift), .out_A(w_A));
	lsrB lsrB1 (.clk(clk), .shift(w_shift), .load(w_ld_rst), .out_B(w_B), .lsb_B(w_lsb_B));
	control control1 (.clk(clk), .lsb_B(w_lsb_B), .init(init), .Z(w_Z), .ld_rst(w_ld_rst), .shift(w_shift), .acc(w_acc), .done(done));

endmodule
