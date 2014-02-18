module parityCreator (Char, ParityBit);
//módulo que genera el bit de paridad par
input [0:6] Char;
output reg ParityBit;

always @(Char) begin
	ParityBit=(^ Char);	//compuerta XOR para generar el bit de paridad
end

endmodule
