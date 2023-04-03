%* setup
bin_fprefix = '../../build/bin';
test_name = 'matrix_rw-test';
bin_fname = append(test_name, '.exe');
fprefix = append('../../build/data/', test_name, '-');
ref_fprefix = append('../ref_data/', test_name, '-');
mat_fname = 'mat.csv';
ref_mat_fname = 'ref_mat.csv';
m_col = 75;
is_single_precision = false;

if is_single_precision
	error_thres = 1e-7; %* single precision
else 
	error_thres = 1e-15;
end

%* create reference data 
magic_mat = magic(m_col);
ref_mat = [magic_mat; magic_mat]./max(magic_mat, [], 'all') - 1/3;
writematrix(ref_mat, append(ref_fprefix, ref_mat_fname), 'Delimiter', ',');
disp(append('Created reference data for ', test_name));

prev_pwd = pwd;
cd(bin_fprefix);

if isfile(bin_fname)
	%* call the test executable
	if system(bin_fname) > 0
		warning(append(bin_fprefix, '/', bin_fname, ' has returned failure.'));
	end
	%* read the results
	mat = readmatrix(append(fprefix, mat_fname));
	%* verify
	max_error = max(mat - ref_mat, [], 'all')

	if max_error < error_thres
		disp(append(test_name, '	ok'));
	else
		disp(append(test_name, '	fail'));
	end
else
	error(append(bin_fprefix, '/', bin_fname, ' does not exist. Use CMake to build the test.'));
end
cd(prev_pwd);