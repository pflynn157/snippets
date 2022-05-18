library IEEE;
use IEEE.std_logic_1164.all;
use std.textio.all;

entity and_tb is
end and_tb;

architecture behavior of and_tb is
    -- Declare our component
    component AND2
        port(clk, A, B : in std_logic; F : out std_logic);
    end component;
    
    -- Bind to the component
    signal clk, A, B, F : std_logic := '0';
    
    -- Clock period definitions
    constant clk_period : time := 10 ns;
begin
    -- Initialize component
    uut: AND2 port map(clk => clk, A => A, B => B, F => F);
    
    --file_process : process
    --    variable l : line;
    --    
    --    file f1 : text open write_mode is "test.txt";
    --    variable file_line : line;
    --    variable word1 : std_logic_vector(3 downto 0) := "1010";
    --begin
    --    write(l, String'("Hello!"));
    --    writeline(output, l);
    --    
    --    write(file_line, to_bitvector(word1));
    --    writeline(f1, file_line);
    --    file_close(f1);
    --    wait;
    --end process;
    
    -- Clock process definitions
    I_clk_process : process
    begin
        clk <= '0';
        wait for clk_period/2;
        clk <= '1';
        wait for clk_period/2;
    end process;
 
    -- Test process
    stim_proc: process
        file input : text open read_mode is "../program.txt";
        variable read_line : line;
        variable word : std_logic_vector(1 downto 0) := "00";
    begin
        -- hold reset state for 100 ns.
        wait for 5 ns;
        
       -- for i in 0 to 3 loop
       while not endfile(input) loop
            readline(input, read_line);
            read(read_line, word);
            report "WORD: " & to_hstring(word);
            
            A <= word(0);
            B <= word(1);
            wait for clk_period;
            
        end loop;
        
        file_close(input);
        wait;
    end process;
end architecture;


