module frequencyDivider(clk, clkSend, Reset);
//Este módulo genera un reloj con una frecuencia menor a la del reloj de la FPGA
input clk, Reset;
output reg clkSend;//señal de salida

//parameter period = 50000000;
//parameter n = 25;
parameter period = 5208;//periodo del nuevo reloj
parameter n =12;
parameter halfPeriod = period/2;//mitad del periodo del nuevo reloj
reg [n:0] counter;

	

always @(posedge clk) begin

	if (Reset)begin//señal externa que inicia el módulo
		counter <= 0;//iniciar el contador en cero
		clkSend <= 0;//el nuevo reloj inicia en cero
	end
	else begin
	
		if (counter == period-1) begin//el contador aumenta desde 0 hasta 5207 es decir 5208 ciclos
			counter <= 0;//reinicia el contador
			clkSend <= 0;//reinicia el nuevo reloj
		end
		else begin
			counter <= counter +1;//aumenta el contador
		end
		if (counter == halfPeriod)begin//cuando el contador llegue a la mitad del periodo 
			clkSend <=1;   			  //el reloj está en estado alto
		end
	end
end
endmodule
