%* setup
bin_dir = '../../build/bin';
dat_dir = '../../build/dat';
ref_dat_dir = "../reference_dat";
test_name = 'matrix_rw-test';
dat_prefix = append(dat_dir, '/', test_name, '-');
ref_dat_prefix = append(ref_dat_dir, '/', test_name, '-');
exe_name = append(test_name, '.exe');
in_arr_fname = 'in_arr.dat';
out_arr_fname = 'out_arr.dat';

is_single_precision = false;
n_dim = 150;
m_dim = 75;

if is_single_precision
	error_thres = 1e-7; %* single precision
else 
	error_thres = 1e-15;
end

%* create reference data 
m = magic(m_dim);
in_arr = [m; m]./max(m, [], 'all') - 1/3;

writematrix(in_arr, append(ref_dat_prefix, in_arr_fname), 'Delimiter', ',');

disp(append('Created reference data for ', test_name));

prev_pwd = pwd;
cd(bin_dir);
if isfile(exe_name)
	%* call the test executable
	if system(exe_name) > 0
		warning(append(bin_dir, '/', exe_name, ' has returned failure.'));
	end

	%* read the results
	out_arr = readmatrix(append(dat_prefix, out_arr_fname));

	%* verify
	max_error = max(in_arr - out_arr, [], 'all')

	if max_error < error_thres
		disp(append(test_name, '	ok'));
	else
		disp(append(test_name, '	fail'));
	end
else
	error(append(bin_dir, '/', exe_name, ' does not exist. Use CMake to build the test.'));
end
cd(prev_pwd);