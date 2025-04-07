<script>
	import { enhance } from '$app/forms';
	import { goto } from '$app/navigation';
	import { authStore, setAuth } from '$lib/stores/auth';
	import { get } from 'svelte/store';
	import { onMount } from 'svelte';

	let user = {
		username: '',
		password: ''
	};
	
	// Μεταβλητή loading
	let isLoading = false;
	// Μεταβλητή για μήνυμα σφάλματος
	let errorMessage = '';

	onMount(async () => {
		const auth = get(authStore);
		if (auth?.token) {
			console.log(auth);
			goto('/');
		}
	});

	function handleSubmit() {
		// Ενεργοποίηση loading κατά την υποβολή
		isLoading = true;
		// Καθαρισμός τυχόν προηγούμενου μηνύματος σφάλματος
		errorMessage = '';
		
		// @ts-ignore
		return async ({ result }) => {
			// Απενεργοποίηση loading όταν λάβουμε απάντηση
			isLoading = false;
			
			if (result.type === 'success') {
				console.log(result);
				setAuth({
					token: result.data.token,
					user: result.data.user
				});
				const auth = get(authStore);
				console.log('\nAuth store : ', auth);
				goto('/');
			} else if (result.type === 'failure') {
				// Λήψη του μηνύματος σφάλματος από το response
				if (result.data.message) {
					// Έλεγχος αν το message είναι αντικείμενο
					if (typeof result.data.message === 'object') {
						errorMessage = result.data.message.message || 'Σφάλμα σύνδεσης';
					} else {
						errorMessage = result.data.message;
					}
				} else {
					errorMessage = 'Λάθος στοιχεία σύνδεσης';
				}
			} else {
				errorMessage = 'Παρουσιάστηκε σφάλμα κατά τη σύνδεση';
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
		Επιστροφή
	</button>
</div>

<div
	class="flex justify-center items-center min-h-screen bg-gradient-to-br from-[#8FC0A9] to-[#68B0AB]"
>
	<div class="bg-[#FAF3DD] p-8 rounded-lg shadow-lg max-w-md w-full">
		<h1 class="text-center text-[#696D7D] text-2xl font-semibold mb-1">Σύνδεση</h1>
		<h1 class="text-center text-[#696D7D] text-lg mb-6">Χαιρόμαστε που σας βλέπουμε ξανά!</h1>

		{#if errorMessage}
			<div class="mb-4 p-3 bg-red-100 border border-red-400 text-red-700 rounded-lg text-sm">
				<p>{errorMessage}</p>
			</div>
		{/if}

		<form method="post" use:enhance={handleSubmit}>
			<input
				name="username"
				type="text"
				bind:value={user.username}
				placeholder="Όνομα χρήστη"
				class="input w-full border-2 border-[#C8D5B9] rounded-lg p-2 mb-4
                 focus:outline-none focus:border-[#68B0AB] bg-white
                 placeholder:text-[#696D7D]/60 text-[#696D7D]"
				required
			/>

			<input
				name="password"
				type="password"
				bind:value={user.password}
				placeholder="Κωδικός πρόσβασης"
				class="input w-full border-2 border-[#C8D5B9] rounded-lg p-2 mb-4
                 focus:outline-none focus:border-[#68B0AB] bg-white
                 placeholder:text-[#696D7D]/60 text-[#696D7D]"
				required
			/>

			<div class="text-center text-[#696D7D] mb-6">
				<span>Δεν έχετε λογαριασμό;</span>
				<a
					href="/auth/register"
					class="ml-2 no-underline text-[#68B0AB] hover:underline hover:opacity-80 transition-all duration-300"
				>
					Εγγραφή
				</a>
			</div>

			<button
				type="submit"
				class="w-full p-2 rounded-lg bg-gradient-to-br from-[#8FC0A9] to-[#68B0AB]
                 text-[#FAF3DD] cursor-pointer hover:opacity-90 transition-all duration-300
                 font-medium shadow-md flex justify-center items-center"
				disabled={isLoading}
			>
				{#if isLoading}
					<!-- Δείκτης φόρτωσης -->
					<svg class="animate-spin -ml-1 mr-2 h-4 w-4 text-white" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24">
						<circle class="opacity-25" cx="12" cy="12" r="10" stroke="currentColor" stroke-width="4"></circle>
						<path class="opacity-75" fill="currentColor" d="M4 12a8 8 0 018-8V0C5.373 0 0 5.373 0 12h4zm2 5.291A7.962 7.962 0 014 12H0c0 3.042 1.135 5.824 3 7.938l3-2.647z"></path>
					</svg>
					Σύνδεση...
				{:else}
					Σύνδεση
				{/if}
			</button>
		</form>

		<div class="text-center text-[#696D7D] text-sm mt-4">
			<a href="/auth/forgot-password" class="text-[#68B0AB] hover:underline hover:opacity-80 transition-all duration-300">
				Ξεχάσατε τον κωδικό σας;
			</a>
		</div>
	</div>
</div>