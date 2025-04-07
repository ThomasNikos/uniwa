<script>
	import { enhance } from '$app/forms';
	import { goto } from '$app/navigation';
	import { authStore, setAuth } from '$lib/stores/auth';
	import { get } from 'svelte/store';
	import { onMount } from 'svelte';

	onMount(async () => {
		const auth = get(authStore);
		if (auth?.token) {
			goto('/');
		}
	});

	let error = '';

	let user = {
		username: '',
		email: '',
		phone: '',
		address: '',
		password: '',
		confirmPassword: ''
	};

	function handleSubmit() {
		// @ts-ignore
		return async ({ result }) => {
			if (result.type === 'success') {
				console.log(result);
				setAuth({
					token: result.data.token,
					user: result.data.user
				});
				const auth = get(authStore);
				console.log('\nAuth store : ', auth);
				goto('/');
			} else {
				alert('Login Failed!');
			}
		};
	}

	function goToHome() {
		goto('/');
	}
</script>

<div class="absolute top-4 left-4">
	<button
		on:click={goToHome}
		class="bg-[#68B0AB] text-[#FAF3DD] py-2 px-4 rounded-lg shadow-md hover:opacity-90 transition-all duration-300"
	>
		Back to Home
	</button>
</div>

<div
	class="flex justify-center items-center min-h-screen bg-gradient-to-br from-[#8FC0A9] to-[#68B0AB] py-8"
>
	<div class="bg-[#FAF3DD] p-8 rounded-lg shadow-lg max-w-md w-full mx-4">
		<h1 class="text-center text-[#696D7D] text-2xl font-semibold mb-6">Create Your Account</h1>

		<form method="post" use:enhance={handleSubmit}>
			<div class="mb-4">
				<label for="username" class="block text-[#696D7D] text-sm mb-1">Username</label>
				<input
					id="username"
					name="username"
					type="text"
					bind:value={user.username}
					placeholder="Choose a username"
					class="input w-full border-2 border-[#C8D5B9] rounded-lg p-2
                   focus:outline-none focus:border-[#68B0AB] bg-white
                   placeholder:text-[#696D7D]/60 text-[#696D7D]"
					required
				/>
			</div>

			<div class="mb-4">
				<label for="email" class="block text-[#696D7D] text-sm mb-1">Email</label>
				<input
					id="email"
					name="email"
					type="email"
					bind:value={user.email}
					placeholder="Enter your email"
					class="input w-full border-2 border-[#C8D5B9] rounded-lg p-2
                   focus:outline-none focus:border-[#68B0AB] bg-white
                   placeholder:text-[#696D7D]/60 text-[#696D7D]"
					required
				/>
			</div>

			<div class="mb-4">
				<label for="phone" class="block text-[#696D7D] text-sm mb-1">Phone Number</label>
				<input
					id="phone"
					name="phone"
					type="tel"
					bind:value={user.phone}
					placeholder="Enter your phone number"
					class="input w-full border-2 border-[#C8D5B9] rounded-lg p-2
                   focus:outline-none focus:border-[#68B0AB] bg-white
                   placeholder:text-[#696D7D]/60 text-[#696D7D]"
					required
				/>
			</div>

			<div class="mb-4">
				<label for="address" class="block text-[#696D7D] text-sm mb-1">Address</label>
				<textarea
					id="address"
					name="address"
					bind:value={user.address}
					placeholder="Enter your address"
					class="input w-full border-2 border-[#C8D5B9] rounded-lg p-2
                   focus:outline-none focus:border-[#68B0AB] bg-white
                   placeholder:text-[#696D7D]/60 text-[#696D7D]
                   min-h-[80px] resize-y"
					required
				></textarea>
			</div>

			<div class="mb-4">
				<label for="password" class="block text-[#696D7D] text-sm mb-1">Password</label>
				<input
					id="password"
					name="password"
					type="password"
					bind:value={user.password}
					placeholder="Create password"
					class="input w-full border-2 border-[#C8D5B9] rounded-lg p-2
                   focus:outline-none focus:border-[#68B0AB] bg-white
                   placeholder:text-[#696D7D]/60 text-[#696D7D]"
					required
				/>
			</div>

			{#if error != ''}
				<p class="text-red-600">{error}</p>
			{/if}

			<div class="text-center text-[#696D7D] mb-6">
				<span>Already have an account?</span>
				<a
					href="/auth/login"
					class="ml-2 no-underline text-[#68B0AB] hover:underline hover:opacity-80 transition-all duration-300"
				>
					Log in
				</a>
			</div>

			<button
				type="submit"
				class="w-full p-2 rounded-lg bg-gradient-to-br from-[#8FC0A9] to-[#68B0AB]
                 text-[#FAF3DD] cursor-pointer hover:opacity-90 transition-all duration-300
                 font-medium shadow-md"
			>
				Create Account
			</button>
		</form>
	</div>
</div>
