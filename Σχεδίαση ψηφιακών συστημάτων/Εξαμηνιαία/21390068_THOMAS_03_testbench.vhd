library ieee;
use ieee.std_logic_1164.all;

entity mips_tb is
end mips_tb;

architecture mipstb of mips_tb is

component mips port(
  clk: in std_logic;
  rst: in std_logic;
  outMips: out std_logic_vector(31 downto 0));
end component;

signal clk,rst: std_logic;
signal outMips: std_logic_vector(31 downto 0);
begin
  M: MIPS port map(clk,rst,outMips);
  cl: process
  variable clktmp,reset: std_logic:='1';
begin
  clktmp:=NOT clktmp;
  clk <= clktmp;
  if (reset='1') then
    rst <= reset;
    reset := '0';
  else
    rst <= '0';
  end if;
  wait for 33 ns;
end process;
end mipstb;

library ieee;
use ieee.std_logic_1164.all;
entity ALU_TB is
end ALU_TB;

architecture TestALU of ALU_TB is

component ALU port(
  in1,in2: in std_logic_vector(31 downto 0);
  opcode: in std_logic_vector(3 downto 0);
  ALUout: out std_logic_vector(31 downto 0);
  zero: out std_logic);
end component;

signal clk,rst: std_ulogic;
signal ind1,ind2,output: std_logic_vector(31 downto 0);
signal oper: std_logic_vector(3 downto 0);
begin
  A: ALU port map(ind1,ind2,oper,output);
  cl: process
  variable clktmp: std_ulogic:='0';
  variable reset: std_ulogic:='1';
begin
  clktmp:= NOT clktmp;
  clk <= clktmp;
  if (reset='1') then
    rst <= reset;
    reset := '0';
  else
    rst <= '0';
  end if;
  wait for 50 ns;
end process;
s: process(clk)
begin
  if (clk='1' and clk'event) then
    ind1 <= "00000000000000000000000010010110";
    ind2 <= "00000000000000000000001000000010";
    oper <= "0010";
  end if;
end process;
end TestALU;
