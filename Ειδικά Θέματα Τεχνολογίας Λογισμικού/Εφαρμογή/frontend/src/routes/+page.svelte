<script>
	import logo from '$lib/images/logo.png';
	import { goto } from '$app/navigation';
	import { get } from 'svelte/store';
	import { authStore } from '$lib/stores/auth';
	import Footer from '$lib/components/Footer.svelte';
	import Hero from '$lib/components/Hero.svelte';
	import Cards from '$lib/components/Cards.svelte';
	import Gaol from '$lib/components/Gaol.svelte';

	const handleRegister = () => {
		goto('/auth/register');
	};

	const handleLogin = () => {
		goto('/auth/login');
	};

	const handleBook = () => {
		goto('/book');
	};

	const handleAdminDashboard = () => {
    goto('/admin');
  };

	// Υποθέτω ότι το authStore περιέχει και το role του χρήστη
	$: isAdmin = get(authStore)?.user?.role === 'admin';
</script>

<svelte:head>
	<title>Comb Barbershop</title>
	<meta name="description" content="Demo project for the Full SvelteKit" />
</svelte:head>

<body>
	
	<header class="fixed top-4 left-4 right-4 z-10">
		<div class="lg:w-1/4 mx-auto bg-comb-white/90 rounded-full py-2 px-3 sm:px-6 shadow-lg">
		  <div class="h-full flex justify-between gap-5 items-center">
			<img class="h-6 w-6 sm:h-8 sm:w-8 rounded-xl" src={logo} alt="Logo" />
			
			<div class="flex items-center gap-1 sm:gap-2 md:gap-4">
			  <!-- Admin Button -->
			  {#if isAdmin && get(authStore)}
				<button
				  on:click={handleAdminDashboard}
				  class="group relative px-2 sm:px-3 lg:px-4 py-1 lg:py-1.5 flex items-center gap-1 sm:gap-2 bg-comb-cyan hover:bg-comb-blue rounded-xl transition-all duration-300 text-comb-white shadow-md hover:shadow-lg"
				>
				  <svg
					xmlns="http://www.w3.org/2000/svg"
					width="16"
					height="16"
					fill="none"
					stroke="currentColor"
					stroke-width="2"
					stroke-linecap="round"
					stroke-linejoin="round"
					class="sm:w-18 sm:h-18 transition-transform duration-300 group-hover:rotate-12"
				  >
					<path d="M16 21v-2a4 4 0 0 0-4-4H5a4 4 0 0 0-4 4v2" />
					<circle cx="8.5" cy="7" r="4" />
					<path d="m17 8-5 5" />
					<path d="m12 8 5 5" />
				  </svg>
				  <span class="font-medium text-xs sm:text-sm">Admin</span>
				</button>
			  {/if}
			  
			  <!-- Register Button -->
			  <button
				on:click={handleRegister}
				class="{get(authStore) ? 'hidden' : ''} px-2 sm:px-3 lg:px-4 py-1 lg:py-1.5 text-comb-white bg-comb-cyan hover:bg-comb-blue rounded-xl transition-colors duration-300 text-xs sm:text-sm font-medium shadow-sm"
			  >
				Register
			  </button>
			  
			  <!-- Login Button -->
			  <button
				on:click={handleLogin}
				class="{get(authStore) ? 'hidden' : ''} px-2 sm:px-3 lg:px-4 py-1 lg:py-1.5 border-2 border-comb-cyan text-comb-cyan hover:bg-comb-white rounded-xl transition-colors duration-300 text-xs sm:text-sm font-medium"
			  >
				Login
			  </button>
			  
			  <!-- Book Now Button -->
			  <button
				on:click={handleBook}
				class="{get(authStore) ? '' : 'hidden'} group relative px-2 sm:px-3 lg:px-4 py-1 lg:py-1.5 flex items-center gap-1 sm:gap-2 bg-comb-cyan hover:bg-comb-blue rounded-xl transition-all duration-300 text-comb-white shadow-md hover:shadow-lg"
			  >
				<svg
				  xmlns="http://www.w3.org/2000/svg"
				  width="16"
				  height="16"
				  fill="none"
				  stroke="currentColor"
				  stroke-width="2"
				  stroke-linecap="round"
				  stroke-linejoin="round"
				  class="sm:w-18 sm:h-18 transition-transform duration-300 group-hover:rotate-12"
				>
				  <path d="M4 19.5v-15A2.5 2.5 0 0 1 6.5 2H20v20H6.5a2.5 2.5 0 0 1 0-5H20" />
				</svg>
				<span class="hidden sm:inline font-medium text-xs sm:text-sm">BOOK NOW</span>
				<span class="sm:hidden font-medium text-xs">BOOK</span>
			  </button>
			</div>
		  </div>
		</div>
	</header>

	<Hero />
	<Cards />

	<section class="bg-bg-2 h-screen relative">
		<svg
			class="absolute top-0 rotate-y-180"
			xmlns="http://www.w3.org/2000/svg"
			viewBox="0 0 1000 100"
			preserveAspectRatio="none"><path fill="#ffff" d="M0 6V0h1000v100L0 6z" /></svg
		>
		<svg
			class="absolute bottom-[-1px] rotate-180"
			xmlns="http://www.w3.org/2000/svg"
			viewBox="0 0 1000 100"
			preserveAspectRatio="none"><path fill="#ffff" d="M0 6V0h1000v100L0 6z" /></svg
		>
	</section>

	<Gaol />

	<section class="bg-bg-3 bg-cover h-screen relative">
		<svg
			class="absolute top-0 rotate-y-180"
			xmlns="http://www.w3.org/2000/svg"
			viewBox="0 0 1000 100"
			preserveAspectRatio="none"><path fill="#ffff" d="M0 6V0h1000v100L0 6z" /></svg
		>
	</section>

	<Footer />
</body>
