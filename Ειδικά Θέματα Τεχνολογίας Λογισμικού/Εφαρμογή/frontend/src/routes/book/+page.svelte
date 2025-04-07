<script>
	// @ts-nocheck
	import { goto } from '$app/navigation';
	import { writable, get } from 'svelte/store';
	import { authStore } from '$lib/stores/auth';
	import { onMount } from 'svelte';
	import { fade, fly } from 'svelte/transition';
	import { quintOut } from 'svelte/easing';

	// Time slot generation
	const startTime = new Date();
	startTime.setHours(10, 0, 0, 0);

	const endTime = new Date();
	endTime.setHours(17, 0, 0, 0);

	const timeSlots = [];
	const duration = 45 * 60 * 1000;

	let time = new Date(startTime);
	while (time <= endTime) {
		timeSlots.push(new Date(time));
		time = new Date(time.getTime() + duration);
	}

	// State variables
	const selectedTime = writable(null);
	const selectedDate = writable(new Date().toISOString().split('T')[0]); // Default to today
	let selectedBarber = 'Νίκος';
	let appointmentType = 'Κλασικό Κουρεμά';
	
	// Μεταβλητές για alerts
	let showAlert = false;
	let alertMessage = '';
	let alertType = 'error'; // 'error', 'success', 'warning'
	let isBooking = false; // Δείκτης για το αν είναι σε εξέλιξη η κράτηση

	onMount(async () => {
		const auth = get(authStore);
		if (!auth?.token) {
			console.log(auth);
			goto('/auth/login');
		}
	});

	// Επιλογή χρονοθυρίδας
	function selectTime(slot) {
		selectedTime.set(slot);
	}

	// Εμφάνιση alert με animation
	function showAlertMessage(message, type = 'error', duration = 5000) {
		alertMessage = message;
		alertType = type;
		showAlert = true;
		
		// Αυτόματο κλείσιμο του alert μετά από καθορισμένο χρόνο
		setTimeout(() => {
			showAlert = false;
		}, duration);
	}

	// Κλείσιμο του alert
	function closeAlert() {
		showAlert = false;
	}

	// Κράτηση ραντεβού
	async function bookAppointment() {
		const user = get(authStore).user;
		
		if (!$selectedTime) {
			showAlertMessage('Παρακαλώ επιλέξτε ώρα για το ραντεβού σας', 'warning');
			return;
		}
		
		isBooking = true;

		// Συνδυασμός επιλεγμένης ημερομηνίας και ώρας
		const selectedDateTime = new Date(
			`${$selectedDate}T${$selectedTime.getHours().toString().padStart(2, '0')}:${$selectedTime.getMinutes().toString().padStart(2, '0')}:00.000Z`
		);
		
		const appointmentData = {
			username: user?.username || 'Guest',
			date: selectedDateTime,
			employee: selectedBarber,
			type: appointmentType
		};

		try {
			const response = await fetch('http://localhost:3000/api/appointments', {
				method: 'POST',
				headers: {
					'Content-Type': 'application/json',
					'Authorization': `Bearer ${get(authStore).token}`
				},
				body: JSON.stringify(appointmentData)
			});

			const responseData = await response.json();
			
			if (!response.ok) {
				// Εμφάνιση μηνύματος σφάλματος
				showAlertMessage(responseData.error || 'Πρόβλημα με την κράτηση!', 'error');
				throw new Error(responseData.error || 'Πρόβλημα με την κράτηση!');
			}

			// Επιτυχής κράτηση
			showAlertMessage('Το ραντεβού καταχωρήθηκε με επιτυχία!', 'success');
			selectedTime.set(null); // Επαναφορά επιλεγμένης ώρας
		} catch (error) {
			console.error('Error booking appointment:', error);
		} finally {
			isBooking = false;
		}
	}

	function goToHome() {
		goto('/');
	}
</script>

<!-- Alert Banner με Animation -->
{#if showAlert}
	<div transition:fly={{ y: -50, duration: 300, easing: quintOut }} 
	     class="fixed top-4 left-1/2 transform -translate-x-1/2 z-50 w-full max-w-md p-4 rounded-lg shadow-lg {alertType === 'error' ? 'bg-red-100 border-red-500 text-red-700' : alertType === 'success' ? 'bg-green-100 border-green-500 text-green-700' : 'bg-yellow-100 border-yellow-500 text-yellow-700'} border-l-4 flex items-center justify-between">
		<div class="flex items-center">
			<!-- Εικονίδιο ανάλογα με τον τύπο του alert -->
			{#if alertType === 'error'}
				<svg class="w-5 h-5 mr-2" fill="currentColor" viewBox="0 0 20 20">
					<path fill-rule="evenodd" d="M18 10a8 8 0 11-16 0 8 8 0 0116 0zm-7 4a1 1 0 11-2 0 1 1 0 012 0zm-1-9a1 1 0 00-1 1v4a1 1 0 102 0V6a1 1 0 00-1-1z" clip-rule="evenodd"></path>
				</svg>
			{:else if alertType === 'success'}
				<svg class="w-5 h-5 mr-2" fill="currentColor" viewBox="0 0 20 20">
					<path fill-rule="evenodd" d="M10 18a8 8 0 100-16 8 8 0 000 16zm3.707-9.293a1 1 0 00-1.414-1.414L9 10.586 7.707 9.293a1 1 0 00-1.414 1.414l2 2a1 1 0 001.414 0l4-4z" clip-rule="evenodd"></path>
				</svg>
			{:else}
				<svg class="w-5 h-5 mr-2" fill="currentColor" viewBox="0 0 20 20">
					<path fill-rule="evenodd" d="M8.257 3.099c.765-1.36 2.722-1.36 3.486 0l5.58 9.92c.75 1.334-.213 2.98-1.742 2.98H4.42c-1.53 0-2.493-1.646-1.743-2.98l5.58-9.92zM11 13a1 1 0 11-2 0 1 1 0 012 0zm-1-8a1 1 0 00-1 1v3a1 1 0 002 0V6a1 1 0 00-1-1z" clip-rule="evenodd"></path>
				</svg>
			{/if}
			<span>{alertMessage}</span>
		</div>
		<button 
			on:click={closeAlert}
			class="text-gray-500 hover:text-gray-700 focus:outline-none"
			aria-label="Close">
			<svg class="w-4 h-4" fill="currentColor" viewBox="0 0 20 20">
				<path fill-rule="evenodd" d="M4.293 4.293a1 1 0 011.414 0L10 8.586l4.293-4.293a1 1 0 111.414 1.414L11.414 10l4.293 4.293a1 1 0 01-1.414 1.414L10 11.414l-4.293 4.293a1 1 0 01-1.414-1.414L8.586 10 4.293 5.707a1 1 0 010-1.414z" clip-rule="evenodd"></path>
			</svg>
		</button>
	</div>
{/if}

<!-- Back to Home Button -->
<div class="absolute top-4 left-4">
	<button
		on:click={goToHome}
		class="bg-[#68B0AB] text-[#FAF3DD] py-2 px-4 rounded-lg shadow-md hover:opacity-90 transition-all duration-300"
	>
		Επιστροφή
	</button>
</div>

<!-- Calendar UI -->
<div
	class="flex justify-center items-center min-h-screen bg-gradient-to-br from-[#8FC0A9] to-[#68B0AB] py-8"
>
	<div class="bg-[#FAF3DD] p-8 rounded-lg shadow-lg max-w-md w-full mx-4">
		<h2 class="text-2xl font-semibold mb-6 text-center text-[#68B0AB]">Κλείστε ραντεβού</h2>

		<!-- Day Selection -->
		<span class="block my-2 text-[#68B0AB] font-semibold">Επιλέξτε Ημέρα:</span>
		<input
			type="date"
			bind:value={$selectedDate}
			min={new Date().toISOString().split('T')[0]}
			class="w-full mb-4 p-2 rounded-md shadow-md bg-[#8FC0A9] text-[#FAF3DD]"
		/>

		<!-- Time Selection -->
		<span class="block my-2 text-[#68B0AB] font-semibold">Επιλέξτε Ώρα:</span>
		<div class="grid grid-cols-2 tab:grid-cols-3 gap-4">
			{#each timeSlots as slot (slot.getTime())}
				<button
					on:click={() => selectTime(slot)}
					class="py-2 px-4 rounded-md shadow-md bg-[#8FC0A9] text-[#FAF3DD] hover:opacity-90 transition-all duration-300"
					class:selected={$selectedTime === slot}
				>
					{slot.toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' })}
				</button>
			{/each}
		</div>

		<!-- Barber Selection -->
		<span class="block my-2 text-[#68B0AB] font-semibold">Επιλογή Μπαρμπέρη:</span>
		<select
			bind:value={selectedBarber}
			class="w-full mb-4 p-2 rounded-md shadow-md bg-[#8FC0A9] text-[#FAF3DD]"
		>
			<option value="Νίκος">Νίκος</option>
			<option value="Φίλιππος">Φίλιππος</option>
		</select>

		<!-- Appointment Type Selection -->
		<span class="block mb-2 text-[#68B0A9] font-semibold">Τύπος ραντεβού:</span>
		<select
			bind:value={appointmentType}
			class="w-full mb-6 p-2 rounded-md shadow-md bg-[#8FC0A9] text-[#FAF3DD]"
		>
			<option value="Κλασικό Κουρεμά">Κλασικό Κουρεμά 10€</option>
			<option value="Περιποίηση γενειάδας">Περιποίηση γενειάδας 15€</option>
			<option value="Πακέτο Premium">Πακέτο Premium 25€</option>
		</select>

		{#if $selectedTime}
			<div class="mt-3 text-center">
				<p class="text-lg text-[#68B0A9]">
					<strong>Ημέρα:</strong>
					{$selectedDate}<br />
					<strong>Ώρα:</strong>
					{$selectedTime.toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' })}<br />
					<strong>Μπαρμπέρης:</strong>
					{selectedBarber}<br />
					<strong>Τύπος:</strong>
					{appointmentType}
				</p>
				<button
					on:click={bookAppointment}
					class="mt-4 bg-[#68B0AB] text-[#FAF3DD] py-2 px-4 rounded-md shadow-md hover:opacity-90 transition-all duration-300 flex justify-center items-center w-full"
					disabled={isBooking}
				>
					{#if isBooking}
						<svg class="animate-spin -ml-1 mr-2 h-4 w-4 text-white" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24">
							<circle class="opacity-25" cx="12" cy="12" r="10" stroke="currentColor" stroke-width="4"></circle>
							<path class="opacity-75" fill="currentColor" d="M4 12a8 8 0 018-8V0C5.373 0 0 5.373 0 12h4zm2 5.291A7.962 7.962 0 014 12H0c0 3.042 1.135 5.824 3 7.938l3-2.647z"></path>
						</svg>
						Επεξεργασία...
					{:else}
						Επιβεβαίωση Κράτησης
					{/if}
				</button>
			</div>
		{/if}
	</div>
</div>

<style>
	.selected {
		background-color: #68b0ab;
		color: #faf3dd;
		font-weight: bold;
	}
</style>