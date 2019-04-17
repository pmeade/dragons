
new Vue({
    el: '#app',
    data: {
        num_aspects: 17,
        primes: [1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53],
        speeds: [3, 1, 2, 3, 4, 6, 7, 9, 10, 12, 15, 16, 19, 21, 22, 24, 27],
        energy: [1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        tension: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        faces: [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        old_faces: [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        change: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],

        header_message: 'Welcome to Dragons',
    },
    created: function () {
        this.clock();
    },
    methods: {

        clock() {
            this.tick();
            setTimeout(this.clock, 1000);
        },

        tick() {
            this.measure_energys();
            this.apply_energys();
        },

        measure_energys() {
            for (var d = 0; d < this.num_aspects; ++d) {
                Vue.set(this.old_faces, d, this.faces[d]);

                var energy_to_transfer = this.energy[d];

                for (var p = d + 1; p < this.num_aspects; ++p) {
                    if (this.energy[p] < Math.sign(this.energy[p]) ? energy_to_transfer:-energy_to_transfer) {
                        var donate = energy_to_transfer / this.primes[p];
                        Vue.set(this.energy, p, this.energy[p] + donate);
                        energy_to_transfer -= donate;
                    }
                }

                Vue.set(this.energy, d, energy_to_transfer);
            }
        },

        apply_energys() {
            for (var d = 0; d < this.num_aspects; ++d) {
                var energy_magnitude = Math.abs(this.energy[d]);

                if (energy_magnitude == 0) continue;

                var direction = Math.sign(this.energy[d]);

                if (energy_magnitude >= this.speeds[d]) {
                    Vue.set(this.faces, d, this.faces[d] + direction);
                    energy_magnitude -= this.speeds[d];
                }
                Vue.set(this.energy, d, energy_magnitude * direction);
                this.wrap_face(d);
            }
        },

        wrap_face(d) {
            while (this.faces[d] > this.primes[d]) this.faces[d] -= this.primes[d];
            while (this.faces[d] < 1) this.faces[d] += this.primes[d];
            Vue.set(this.faces, d, this.faces[d]); // Not sure if this works to make page see updates.
        },

        add_dragos(dragos) {
            Vue.set(this.energy, 0, this.energy[0] + dragos);
        },

        take_dragos(dragos) {
            Vue.set(this.energy, 0, this.energy[0] - dragos);
        }
    }
})