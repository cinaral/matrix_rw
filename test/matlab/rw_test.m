%** setup *%
test_name = 'rw_test';
bin_fprefix = '../../build/bin';
bin_fname = append(test_name, '.exe');
ref_fprefix = append('../ref_data/', test_name, '-');
mat_fname = 'matrix.csv';
m_col = 75;

%** create reference data *%
magic_mat = magic(m_col);
ref_mat = [magic_mat; magic_mat]./max(magic_mat, [], 'all') - 1/3;
writematrix(ref_mat, append(ref_fprefix, mat_fname), 'Delimiter', ',');
disp(append('Created reference data for ', test_name));

%** call the test binary *%
prev_pwd = pwd;
cd(bin_fprefix);

if isfile(bin_fname)
	if system(bin_fname) == 0
		disp(append(test_name, '	ok'));
	else 
		disp(append(test_name, '	fail'));
	end
else
	error(append(bin_fprefix, '/', bin_fname, ' does not exist. Use CMake to build the test.'));
end
cd(prev_pwd);